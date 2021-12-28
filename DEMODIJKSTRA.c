// Chuong trình C cho thuat toán duong dan ngan nhat nguon don cua Dijkstra. Chuong trình dành cho bieu dien  ma tran ke cua do thi
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

//So dinh trong do thi
#define V 9

//  hàm  tìm di?nh có  khoa?ng cách nho? nhat, tu ta.p ho.p các di?nh chua có trong cây duong di ngan nhat
int minDistance(int dist[],bool sptSet[])
{
	int min = INT_MAX, min_index;// khoi tao gia tri to'i thie?u
	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;
	return min_index;
}


// Hàm in duong di ngan nhat tu nguon den j (su dung mang cha)
void printPath(int parent[], int j)
{

	// truong hop co so : neu j la nguon
	if (parent[j] == - 1)
		return;

	printPath(parent, parent[j]);

	printf("%d ", j);
}
//Viec luu vet duong di này có the thuc hien trong quá trình to'i uu giá tri dist[v] nhu sau:
//Goi parent[v] là dinh lien truoc cua v trên 1 trong các duong di ngan nhat tìm duoc.
//Khi dó tai buo'c to'i uu dist[u], ta thuc hien cap nhat lai parent[u]:
//parent[u]=v


// Ham in ma?ng khoang cach da~ xay dung
int printSolution(int dist[], int n, int parent[])
{
	int src = 0;
	printf("Dinh\t Khoang cach\tDuong di");
	for (int i = 1; i < V; i++)
	{
		printf("\n%d -> %d \t\t %d\t\t%d ",	src, i, dist[i], src);
		printPath(parent, i);
	}
}

//Hàm thuc hien thuat toán duong da~n nga'n nhat nguo`n duy nhat cua Dijkstra cho mot do thi duoc bieu dien bang cách su dung bieu dien ma tran ke
void dijkstra(int graph[V][V], int src)
{
	int dist[V];	// Mang dau ra. dist [i] se giu khoang cách ngan nhat tu src den i
	bool sptSet[V];// sptSet[i] la du'ng neu dinh i duoc bao gom trong cây duong di ngan nhat hoac khoang cách ngan nhat tu src den i duoc hoàn thie.n
	int parent[V];// Ma?ng chính de luu tru~ cây duong di ngan nhat
	for (int i = 0; i < V; i++) //Khoi tao tat ca khoang cách duoi dang vo^ cu`ng và stpSet [] là false
	{
		parent[0] = -1;
		dist[i] = INT_MAX;
		sptSet[i] = false;
	}

	// khoang ca'ch cu?a dinh nguo^`n voi chinh no luon bang 0
	dist[src] = 0;

	// Tim duong ngan nhat cho tat ca cac dinh
	for (int count = 0; count < V - 1; count++)
	{

		int u = minDistance(dist, sptSet);// Chon di?nh có khoang cách toi thieu tu tap hop các dinh chua duoc xu lý. u luôn = src trong lan lap dau tiên.
		sptSet[u] = true;// Ðánh dau dinh dã chon là da xu ly


		// Cap nhat giá tri dist cua các dinh lien ke cua dinh da chon.
		for (int v = 0; v < V; v++)

			//Cap nhat dist [v] chi? khi không có trong sptSet, có mot canh tu u den v và tong tro.ng so cua duong dan~ tu src den v den u nho? hon giá tri hien tai cua dist [v]
			if (!sptSet[v] && graph[u][v] &&
				dist[u] + graph[u][v] < dist[v])
			{
				parent[v] = u;
				dist[v] = dist[u] + graph[u][v];
			}
	}

	//in mang khoang cach da xay dung
	printSolution(dist, V, parent);
}
// Driver Code
int main()
{
	// Vi du minh hoa
	int graph[V][V] = { {0, 4, 0, 0, 0, 0, 0, 8, 0},
					    {4, 0, 8, 0, 0, 0, 0, 11, 0},
						{0, 8, 0, 7, 0, 4, 0, 0, 2},
						{0, 0, 7, 0, 9, 14, 0, 0, 0},
						{0, 0, 0, 9, 0, 10, 0, 0, 0},
						{0, 0, 4, 14, 10, 0, 2, 0, 0},
						{0, 0, 0, 0, 0, 2, 0, 1, 6},
						{8, 11, 0, 0, 0, 0, 1, 0, 7},
						{0, 0, 2, 0, 0, 0, 6, 7, 0}
					};

	dijkstra(graph, 0);
	return 0;
}
