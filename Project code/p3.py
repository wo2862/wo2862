input = [[4, 3, 2, 1],
         [0, 0, 0, 0],
         [0, 0, 9, 0],
         [1, 2, 3, 4]]
N = 4

forest = []

def problem3(input):
    bear_size = 2
    honeycomb_count = 0
    time = 0
    bear_x, bear_y = 0, 0
    # 입력 힌트

    # forest 리스트를 input 리스트로 초기화
    forest = [row[:] for row in input]
    
    # 곰의 초기 위치 찾기
    for i in range(N):
        for j in range(N):
            if forest[i][j] == 9:
                bear_x, bear_y = i, j
                forest[i][j] = 0
    print("곰의 초기 위치 x : {0}, y : {1}".format(bear_x, bear_y))

    #여기에서부터 코드를 작성하세요.
    from collections import deque

    def bfs(x, y, size):
        visited = [[-1] * N for _ in range(N)]
        queue = deque()
        queue.append((x, y))
        visited[x][y] = 0
        edible = []

        while queue:
            cx, cy = queue.popleft()
            for dx, dy in [(-1, 0), (0, -1), (0, 1), (1, 0)]:
                nx, ny = cx + dx, cy + dy
                if 0 <= nx < N and 0 <= ny < N and visited[nx][ny] == -1:
                    if forest[nx][ny] <= size:
                        visited[nx][ny] = visited[cx][cy] + 1
                        if 0 < forest[nx][ny] < size:
                            edible.append((visited[nx][ny], nx, ny))
                        queue.append((nx, ny))
        if not edible:
            return None
        edible.sort()
        return edible[0]  # (거리, x, y)

    while True:
        result = bfs(bear_x, bear_y, bear_size)
        if result is None:
            break
        dist, nx, ny = result
        time += dist
        bear_x, bear_y = nx, ny
        forest[nx][ny] = 0
        honeycomb_count += 1
        if honeycomb_count == bear_size:
            bear_size += 1
            honeycomb_count = 0

    result = time
    return result

result = problem3(input)

assert result == 14
print("정답입니다.")

