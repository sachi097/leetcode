/*
// Definition for a QuadTree node.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;

    
    public Node() {
        this.val = false;
        this.isLeaf = false;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }
    
    public Node(boolean val, boolean isLeaf) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }
    
    public Node(boolean val, boolean isLeaf, Node topLeft, Node topRight, Node bottomLeft, Node bottomRight) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = topLeft;
        this.topRight = topRight;
        this.bottomLeft = bottomLeft;
        this.bottomRight = bottomRight;
    }
}
*/

class Solution {

    boolean isAllSame(int[][] grid, int x, int y, int n){
        int prev = grid[x][y];
        for(int i=x; i< x + n; i++){
            for(int j=y; j< y + n; j++){
                if(grid[i][j] != prev){
                    return false;
                }
            }
        }
        return true;
    }

    Node divideGrid(int[][] grid, int x, int y, int n){
        if(isAllSame(grid, x, y, n)){
            return new Node(grid[x][y] == 1, true);
        }
        else{
            Node root = new Node(grid[x][y] == 1, false);
            root.topLeft = divideGrid(grid, x, y, n/2);
            root.topRight = divideGrid(grid, x, y + n/2, n/2);
            root.bottomLeft = divideGrid(grid, x + n/2, y, n/2);
            root.bottomRight = divideGrid(grid, x + n/2, y + n/2, n/2);
            return root;
        }
        
    }

    public Node construct(int[][] grid) {
        int n = grid.length;
        return divideGrid(grid, 0, 0, n);
    }
}