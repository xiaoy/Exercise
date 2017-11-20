import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdStats;

public class PercolationStats{
    private double m_fraction[] = null;
    private int m_trials = 0;
    private int m_percolateIndex = 0;
    private double m_mean = 0;
    private double m_stddev = 0;
    public PercolationStats(int n, int trials){
        if(n <= 0 || trials <= 0){
            throw new IllegalArgumentException();
        }
        m_trials = trials;
        m_fraction = new double[m_trials];

        int gridCount = n * n;

        for(int i = 0; i < m_trials; ++i){
            Percolation p = new Percolation(n);
            int[] a = StdRandom.permutation(gridCount);
            int openIndex = 0;
            while(!p.percolates()){
                openIndex += 1;
                openSite(p, n, a[openIndex]);
            }
            m_fraction[m_percolateIndex] = (double)openIndex / gridCount;
            m_percolateIndex += 1;
        }
    }

    private void openSite(Percolation p, int n, int openIndex) {
        int row = openIndex / n + 1; 
        int col = openIndex % n + 1;
        p.open(row, col);
    }

    public double mean(){
        if(m_mean == 0){
            m_mean = StdStats.mean(m_fraction, 0, m_percolateIndex);
        }
        return m_mean;
    }

    public double stddev(){
        if(m_stddev == 0){
            double powMeanSum = 0;
            double[] devArr = new double[m_percolateIndex];
            for(int i = 0; i < m_percolateIndex; ++i){
                double det = (m_fraction[i] - mean());
                devArr[i] = det * det;
            }

            m_stddev = StdStats.stddev(devArr); 
        }
       return m_stddev;
    }

    public double confidenceLo(){
        double sqrtCount = Math.sqrt(m_percolateIndex);
        return mean() - (1.96 * stddev()) / sqrtCount;
    }

    public double confidenceHi(){
        double sqrtCount = Math.sqrt(m_percolateIndex);
        return mean() + (1.96 * stddev()) / sqrtCount;
    }

    public static void main(String[] args){
        if(args.length != 2){
            StdOut.println("must 2 argument, ex:PercolationStats 200 100");
            throw new IllegalArgumentException();
        }

        int n = Integer.parseInt(args[0]);
        int trials = Integer.parseInt(args[1]);

        PercolationStats stat = new PercolationStats(n, trials);
        StdOut.println("mean                        = " + stat.mean());
        StdOut.println("stddev                      = " + stat.stddev());
        StdOut.printf("95%% confidence interval     = [%g, %g]\n", stat.confidenceLo(), stat.confidenceHi());
    }
}