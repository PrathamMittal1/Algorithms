import java.util.Arrays;
import java.util.Scanner;

public class AllPairShortestPath {
    int[][] graph;
    int nodes, edges;
    private static final int INF = 999;
    AllPairShortestPath(int n, int e){
        this.graph = new int[n][n];
        this.nodes=n;
        this.edges=e;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (i==j) graph[i][j] = 0;
                else graph[i][j] = INF;
            }
        }
    }
    void addEdge(int s, int d, int w){
        graph[s][d] = w;
    }
    void showGraph() {
        for (int[] i : graph) System.out.println(Arrays.toString(i));
    }
    void Floyd(){
        int[][] D = graph;
        for (int k=0; k<nodes; k++)
            for (int i=0; i<nodes; i++)
                for (int j=0; j<nodes; j++){
                    D[i][j] = Math.min(D[i][j], (D[i][k] + D[k][j]));
                }

    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter number of nodes: ");
        int nodes = scanner.nextInt();
        System.out.print("Enter number of edges: ");
        int edges = scanner.nextInt();
        AllPairShortestPath map = new AllPairShortestPath(nodes,edges);
        scanner.nextLine();
        System.out.println("Enter source destination weight of edges one by one...");
        for (int i=0;i<edges;i++){
            String[] str = scanner.nextLine().split(" ");
            map.addEdge(Integer.parseInt(str[0]),Integer.parseInt(str[1]),Integer.parseInt(str[2]));
        }
        System.out.println("Given graph is ");
        map.showGraph();
        System.out.println("All Pair Shortest Path graph is ");
        map.Floyd();
        map.showGraph();
    }
}
