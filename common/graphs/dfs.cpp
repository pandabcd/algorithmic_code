

bool visited[mx] = {0};

void dfs(LL s)
{
	visited[s]=true;
	for(LL i=0;i<adj[s].size();i++)
	{
		LL v=adj[s][i];
		if(!visited[v])
			dfs(v);
	}
}