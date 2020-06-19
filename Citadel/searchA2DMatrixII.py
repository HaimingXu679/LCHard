class Solution:
    def searchMatrix(self, matrix, target):
        if not matrix: 
            return False
        m, n = len(matrix), len(matrix[0])
        row, col = 0, n - 1
        while row < m and col >= 0:
            if matrix[row][col] == target:
                return True
            if matrix[row][col] < target:
                row += 1
                continue
            col -= 1
        return False
