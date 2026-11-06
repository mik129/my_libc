#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_libc.h"

struct node {
	int x;
	int y;
	int cost;
};

struct heap {
	struct node *data;
	int size;
	int capacity;
};

static int
hex_val(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	return (-1);
}

static void
heap_push(struct heap *h, int x, int y, int cost)
{
	int i;
	int p;
	struct node tmp;

	if (h->size >= h->capacity)
		return;
	i = h->size++;
	h->data[i].x = x;
	h->data[i].y = y;
	h->data[i].cost = cost;
	while (i > 0) {
		p = (i - 1) / 2;
		if (h->data[p].cost <= h->data[i].cost)
			break;
		tmp = h->data[p];
		h->data[p] = h->data[i];
		h->data[i] = tmp;
		i = p;
	}
}

static struct node
heap_pop(struct heap *h)
{
	struct node res;
	struct node tmp;
	int i;
	int left;
	int right;
	int smallest;

	res = h->data[0];
	h->data[0] = h->data[--h->size];
	i = 0;
	while (1) {
		left = 2 * i + 1;
		right = 2 * i + 2;
		smallest = i;
		if (left < h->size &&
		    h->data[left].cost < h->data[smallest].cost)
			smallest = left;
		if (right < h->size &&
		    h->data[right].cost < h->data[smallest].cost)
			smallest = right;
		if (smallest == i)
			break;
		tmp = h->data[i];
		h->data[i] = h->data[smallest];
		h->data[smallest] = tmp;
		i = smallest;
	}
	return (res);
}

static void
print_num(int n)
{
	char buf[16];
	int i;

	if (n == 0) {
		write(1, "0\n", 2);
		return;
	}
	i = 0;
	while (n > 0) {
		buf[i++] = '0' + (n % 10);
		n /= 10;
	}
	while (i > 0) {
		write(1, &buf[--i], 1);
	}
	write(1, "\n", 1);
}

int
main(int argc, char **argv)
{
	int fd;
	char buf[65536];
	ssize_t bytes;
	int grid[160][160];
	int dist[160][160];
	int parent_x[160][160];
	int parent_y[160][160];
	int rows;
	int cols;
	int r;
	int c;
	ssize_t i;
	int v1;
	int v2;
	struct heap h;
	struct node heap_buf[160 * 160 * 4];
	struct node curr;
	int dx[4] = { 0, 0, 1, -1 };
	int dy[4] = { 1, -1, 0, 0 };
	int nx;
	int ny;
	int nc;
	char path[4096];
	int path_len;
	int px;
	int py;
	int prev_x;
	int prev_y;
	char dir;

	if (argc < 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	bytes = read(fd, buf, sizeof(buf));
	close(fd);
	if (bytes <= 0)
		return (1);
	rows = 0;
	cols = 0;
	r = 0;
	c = 0;
	i = 0;
	while (i < bytes) {
		if (buf[i] == ' ' || buf[i] == '\r') {
			i++;
			continue;
		}
		if (buf[i] == '\n') {
			if (c > 0) {
				if (cols == 0)
					cols = c;
				r++;
				c = 0;
			}
			i++;
			continue;
		}
		v1 = hex_val(buf[i]);
		v2 = hex_val(buf[i + 1]);
		if (v1 != -1 && v2 != -1) {
			grid[r][c] = (v1 << 4) | v2;
			c++;
			i += 2;
		} else {
			i++;
		}
	}
	if (c > 0) {
		if (cols == 0)
			cols = c;
		r++;
	}
	rows = r;

	r = 0;
	while (r < rows) {
		c = 0;
		while (c < cols) {
			dist[r][c] = 2147483647;
			parent_x[r][c] = -1;
			parent_y[r][c] = -1;
			c++;
		}
		r++;
	}

	dist[0][0] = grid[0][0];
	h.data = heap_buf;
	h.size = 0;
	h.capacity = 160 * 160 * 4;
	heap_push(&h, 0, 0, grid[0][0]);

	while (h.size > 0) {
		curr = heap_pop(&h);
		if (curr.cost > dist[curr.y][curr.x])
			continue;
		if (curr.y == rows - 1 && curr.x == cols - 1)
			break;
		i = 0;
		while (i < 4) {
			nx = curr.x + dx[i];
			ny = curr.y + dy[i];
			if (nx >= 0 && nx < cols && ny >= 0 && ny < rows) {
				nc = curr.cost + grid[ny][nx];
				if (nc < dist[ny][nx]) {
					dist[ny][nx] = nc;
					parent_x[ny][nx] = curr.x;
					parent_y[ny][nx] = curr.y;
					heap_push(&h, nx, ny, nc);
				}
			}
			i++;
		}
	}

	print_num(dist[rows - 1][cols - 1]);

	path_len = 0;
	px = cols - 1;
	py = rows - 1;
	while (px != 0 || py != 0) {
		prev_x = parent_x[py][px];
		prev_y = parent_y[py][px];
		if (px == prev_x + 1)
			dir = 'R';
		else if (px == prev_x - 1)
			dir = 'L';
		else if (py == prev_y + 1)
			dir = 'D';
		else
			dir = 'U';
		path[path_len++] = dir;
		px = prev_x;
		py = prev_y;
	}

	i = path_len;
	while (i > 0) {
		write(1, &path[--i], 1);
	}
	write(1, "\n", 1);

	return (0);
}