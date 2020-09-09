public class Network {
    boolean visited[];
    public int solution(int n, int[][] computers) {
        int answer = 0;
        visited = new boolean[n];
        for (int i = 0; i < n; i++){
            if (visited[i] == false){
                answer++;
                visited[i] = true;
                dfs(i, computers);
            }
        }
        return answer;
    }
    public void dfs(int here, int [][] computers){
        for (int i =0; i < computers.length; i++){
            if (computers[here][i] == 1 && visited[i] == false){
                visited[i] = true;
                dfs(i, computers);
            }
        }
    }

}
