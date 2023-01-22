import java.util.Arrays;
import java.util.Scanner;

class MinimumSpanningTree {
    int[][] graph;
    int nodes;
    int[][] edges;
    int path;
    MinimumSpanningTree(int n, int e) {
        graph = new int[n][n];
        nodes = n;
        edges = new int[e][3];
    }

    MinimumSpanningTree(int[][] graph, int n) {
        this.graph = graph;
        this.nodes = n;
        path = 0;
    }

    void addEdge(int s, int d, int w) {
        graph[s][d] = w;
        graph[d][s] = w;
        edges[path][0] = s; edges[path][1] = d; edges[path][2] = w;
        path=path+1;
    }

    void showGraph() {
        for (int[] i : graph) System.out.println(Arrays.toString(i));
    }

    MinimumSpanningTree Kruskal() {
        //this.SyncEdges();
        int encounter = 0, k = 0;
        int[][] minimalSpanningTree = new int[nodes][nodes];
        int[] V = new int[nodes];
        int min = 0;
        for (int i = 0; i < path; i++) {           //selection sort
            for (int j = 1; j < path; j++)
                if (edges[i][2] < edges[min][2]){
                    min = i;
                    int[] temp = edges[0];
                    edges[0] = edges[min];
                    edges[min] = temp;
                    min = 0;
            }
        }
        while (encounter < nodes-1) {
            int[] ei = edges[k];
            if (V[ei[1]] == 1) {
                k = k + 1;
                continue;
            }
            int ui = ei[0], vi = ei[1], wi = ei[2];
            minimalSpanningTree[ui][vi] = wi;
            minimalSpanningTree[vi][ui] = wi;
            V[vi] = 1;
            k = k + 1;
            encounter = encounter + 1;
        }
        return new MinimumSpanningTree(minimalSpanningTree, nodes);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter number of nodes: ");
        int nodes = scanner.nextInt();
        System.out.print("Enter number of edges: ");
        int edges = scanner.nextInt();
        MinimumSpanningTree graph = new MinimumSpanningTree(nodes,edges);
        int[][] edgeList = new int[edges][];
        scanner.nextLine();
        System.out.println("Enter source, destination, weight of edges one by one...");
        for (int i = 0; i < edges; i++) {
            String[] str = scanner.nextLine().split(" ");
            graph.addEdge(Integer.parseInt(str[0]), Integer.parseInt(str[1]), Integer.parseInt(str[2]));
            edgeList[i] = new int[]{Integer.parseInt(str[0]), Integer.parseInt(str[1]), Integer.parseInt(str[2])};

        }
        System.out.println("Given graph is ");
        graph.showGraph();
        MinimumSpanningTree newGraph = graph.Kruskal();
        System.out.println("Minimal spanning tree of given graph is ");
        newGraph.showGraph();
    }
}