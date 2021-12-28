// Chuong trình in BFS truyen tu mot dinh nguon dã cho. BFS (int s) di qua các dinh có the dat duoc tu s.
#include <iostream>
#include <list>

using namespace std;

// Lop này bieu dien mot do thi có huong bang cách su dung bieu dien danh sách ke
class Graph
{
	int V; // So dinh

	// Con tro den mot mang chua danh sách ke
	list<int> *adj;
public:
	Graph(int V); // Ham khoi tao

	//Ham them 1 canh vao do thi
	void addEdge(int v, int w);

	// in BFS truyen tai tu 1 nguon nhat dinh S
	void BFS(int s);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Them w vao danh sach cua v
}

void Graph::BFS(int s)
{
	//danh dau cac dinh la khong duoc tham
	bool *visited = new bool[V];
	for(int i = 0; i < V; i++)
		visited[i] = false;

	// Tao hang doi cho BFS
	list<int> queue;

	// Danh dau nut hien tai la da truy cap va xep vao hang doi
	visited[s] = true;
	queue.push_back(s);

	// 'i' se duoc su dung de lay tat ca cac dinh lien ke cua 1 dinh
	list<int>::iterator i;

	while(!queue.empty())
	{
		// Xep hang doi 1 dinh tu hang doi va in no
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		// Lay tat ca cac dinh lien ke cua dinh s . Neu 1 vung lien ke chua duoc truy cap , hay danh dau no da duoc truy cap va xep hang
		for (i = adj[s].begin(); i != adj[s].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}

int main()
{
	// tao 1 do thi cho trong so do tren
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "(bat dau tu dinh 2) \n";
	g.BFS(2);

	return 0;
}

