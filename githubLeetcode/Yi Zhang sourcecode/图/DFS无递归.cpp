

void DFS(int graph[][4],int N,int start)
{
	stack<int> st;st.push(start);
	int *visited=new int[N];
	memset(visited,0,sizeof(int)*N);
	
	while(!st.empty()){
		int cur=st.top();
		if(visited[cur]==0){
			cout<<cur<<endl;
			visited[cur]=1;
		}

		int i;
		for(i=0;i<N;++i) {
			if(graph[cur][i]==1 && visited[i]==0){
				st.push(i);break;
			}
    }
			if(i==N) st.pop();
	}

	free(visited);
}
void main()  
{ 
	int graph[][4]={{0,0,0,0},{0,0,1,1},
				 {1,0,0,1},{1,0,1,0}};
	DFS(graph,4,1);
}  