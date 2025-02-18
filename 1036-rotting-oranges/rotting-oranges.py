class Solution(object):

    def orangesRotting(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """

        queue = []
        time = 0
        fresh_oranges = 0
        m = len(grid)
        n = len(grid[0])

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    fresh_oranges += 1
                if grid[i][j] == 2:
                    queue.append([i,j,time])
        
        if fresh_oranges == 0:
            return 0

        directions = [(0,1), (0,-1), (1,0), (-1,0)]
        time = 0
        while len(queue) != 0:
            x,y,time = queue[0]
            queue = queue[1:]
            for dx,dy in directions:
                nx = x+dx
                ny = y+dy
                if 0 <= nx < m and 0 <= ny < n and grid[nx][ny] == 1:
                    grid[nx][ny] = 2
                    queue.append([nx,ny,time+1])
                    fresh_oranges -= 1
                            
        if fresh_oranges != 0:
            return -1
        else:
            return time