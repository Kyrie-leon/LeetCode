//右上角开始查找
bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target){
    if(matrixSize == 0 || matrixColSize == NULL)
        return false;
    int row = 0;
    int col = *matrixColSize - 1;
    while(row < matrixSize && col >=0)
    {
        if(target == matrix[row][col])
        {
            return true;
        }
        else if(target > matrix[row][col])
        {
            ++row;
        }
        else
        {
            --col;
        }
    }

    return false;
}