/**
 *
 * @author Mayank
 */
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;

public class KruskalMST{
    public static void main(String args[]){
        Edge[] edges= new Edge[5];
        int noOfVertices=4;
        int[] src={1,2,1,4,1};
        int[] dest={2,3,4,3,3};
        int[] weight={1,4,3,2,10};
        for(int i=0;i<5;i++){
            edges[i]= new Edge(src[i],dest[i],weight[i]);
        }
        Arrays.sort(edges, new Comparator<Edge>(){
            @Override
            public int compare(Edge e1, Edge e2){
                return e1.weight-e2.weight;
            }
        });
        DisjointSet ds= new DisjointSet();
        for(int i=1;i<=noOfVertices;i++){
            ds.makeSet(i);
        }
        int k=0;
        Edge[] result= new Edge[noOfVertices-1];
        for(int i=0;i<5;i++){
            if(ds.findSet(edges[i].src).id!=ds.findSet(edges[i].dest).id){
                result[k++]=edges[i];
                ds.union(edges[i].src,edges[i].dest);
                if(k==result.length)
                    break;
            }
        }
        for(int i=0;i<result.length;i++){
            System.out.println(result[i].src+"-->"+result[i].dest+"="+result[i].weight);
        }
    }
}

class DisjointSet {
    private HashMap<Integer,Node> map= new HashMap<Integer,Node>();
    class Node{
        int id;
        Node parent;
        int rank;
        Node(int i){
            id=i;
        }
    }
    public void makeSet(int num){
        Node node= new Node(num);
        node.parent=node;
        node.rank=1;
        map.put(num,node);
    }
    public boolean union(int src, int dest){
        Node parent1=findSet(src);
        Node parent2=findSet(dest);
        if(parent1.id==parent2.id){
            return false;
        }
        if(parent1.rank>=parent2.rank){
            parent1.rank=(parent1.rank==parent2.rank)?(parent1.rank+1):parent1.rank;
            parent2.parent=parent1;
        }
        else{
            parent1.parent=parent2;
        }
        return true;
    }
    public Node findSet(int num){
        return findSet(map.get(num));
    }
    public Node findSet(Node node){
        Node par= node.parent;
        if(par.id==node.id)
            return par;
        node.parent=findSet(node.parent);
        return node.parent;
    }
    
}
class Edge{
    int src, dest, weight;
    Edge(int src,int dest, int weight){
        this.src= src;
        this.dest= dest;
        this.weight=weight;
    }
}
