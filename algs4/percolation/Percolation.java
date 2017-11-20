import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class Percolation {
    private WeightedQuickUnionUF m_wQuickUnionUF; 
    private int m_openIndex = 0;
    private boolean[][] m_grid = null;
    private int m_colLen = 0;
    private int m_gridCount = 0;

    public Percolation(int n) {
        if(n <= 0) {
            throw new IllegalArgumentException();
        }

        m_colLen = n;
        m_gridCount = n * n;
        m_grid = new boolean[m_colLen][m_colLen];
        reset();
    }

    private void reset() {
        m_openIndex = 0;
        m_wQuickUnionUF = new WeightedQuickUnionUF(m_colLen * m_colLen + 2);
        for(int i = 0; i < m_colLen; ++i) {
            for(int j = 0; j < m_colLen; ++j) {
                m_grid[i][j] = false;
            }
        }
    }

    private void union(int row, int col) {
        int index = getIndex(row, col);
        if(row == 0) {
            int first = m_gridCount;
            m_wQuickUnionUF.union(first, index);
        }

        if(row == (m_colLen - 1)) {
            int last = m_gridCount + 1;
            m_wQuickUnionUF.union(index, last);
        }

        unionLeft(row, col);
        unionUp(row, col);
        unionRight(row, col);
        unionDown(row, col);
    }

    private int getIndex(int row, int col) {
        return row * m_colLen + col;
    }

    private void unionLeft(int row, int col) {
        int leftRow = row - 1;
        if(leftRow < 0){
            return;
        }

        if(isOpen(leftRow + 1, col + 1)) {
            int leftIndex = getIndex(leftRow, col);
            int index = getIndex(row, col);
            m_wQuickUnionUF.union(leftIndex, index);
        }
    }

    private void unionRight(int row, int col) {
        int rowRight = row + 1;
        if(rowRight >= m_colLen){
            return;
        }

        if(isOpen(rowRight + 1, col + 1)) {
            int rightIndex = getIndex(rowRight, col);
            int index = getIndex(row, col);
            m_wQuickUnionUF.union(index, rightIndex);
        }
    }

    private void unionDown(int row, int col) {
        int downCol = col + 1;
        if(downCol >= m_colLen){
            return;
        }

        if(isOpen(row + 1, downCol + 1)) {
            int downIndex = getIndex(row, downCol);
            int index = getIndex(row, col);
            m_wQuickUnionUF.union(downIndex, index);
        }
    }

    private void unionUp(int row, int col) {
        int upCol = col - 1;
        if(upCol < 0) {
            return;
        }

        if(isOpen(row + 1, upCol + 1)) {
            int upIndex = getIndex(row, upCol);
            int index = getIndex(row, col);
            m_wQuickUnionUF.union(upIndex, index);
        }
    }

    public void open(int row, int col){
        if(row < 1 || row > m_colLen || col < 1 || col > m_colLen){
            StdOut.println(row + " " + col);
            throw new IllegalArgumentException();
        }

        if(!isOpen(row, col)){
            row = row - 1;
            col = col -1;
            m_grid[row][col] = true;
            m_openIndex += 1;
            union(row, col);
        }
    }

    public boolean isOpen(int row, int col) {
        if(row < 1 || row > m_colLen || col < 1 || col > m_colLen){
            throw new IllegalArgumentException();
        }
        row = row - 1;
        col = col - 1;

        return m_grid[row][col];
    }

    public boolean isFull(int row, int col) {
        if(row < 1 || row > m_colLen || col < 1 || col > m_colLen){
            throw new IllegalArgumentException();
        }
        row = row - 1;
        col = col - 1;
        int first = m_gridCount; 
        int index = getIndex(row, col);
        return m_wQuickUnionUF.connected(first, index);
    }

    public int numberOfOpenSites() {
        return m_openIndex;
    }

    private boolean isFinished() {
        int first = m_gridCount; 
        int last = first + 1;
        return m_wQuickUnionUF.connected(first, last);
    }

    public boolean percolates() {
        int first = m_gridCount; 
        int last = first + 1;
        return m_wQuickUnionUF.connected(first, last);
    }

    public static void main(String[] args) {
        int n = StdIn.readInt();
        Percolation p = new Percolation(n);
        String str;
        while((str = StdIn.readLine()) != null){
            if(str.isEmpty()){
                continue;
            }
            StdOut.println(str);
            String[] strArr = str.split("\\s+");
            int a = Integer.parseInt(strArr[0]);
            int b = Integer.parseInt(strArr[1]);
            p.open(a, b);
            StdOut.println("isFull:" + p.isFull(a, b));
            StdOut.println("isOpen:" + p.isOpen(a, b));
        }
        StdOut.println(p.numberOfOpenSites());
        StdOut.println(p.percolates());
    }
}