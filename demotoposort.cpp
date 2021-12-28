#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// thêm cạnh trong 1 biểu đồ có hướng
void add(vector <int> list[],int u,int v)
{
    list[u].push_back(v);//Thêm phần tử vào cuối của dãy vecto -> Them cac cp cạnh
}
// Duyệt DFS từ nút nguồn s
void DFS(int s,vector <int> list[],bool *vis,stack <int> &st)
{
    vis[s] = true;//Thăm nút nguồn đầu tiên

    for( int i : list[s])
    {

        if(!vis[i])//Nếu nút chưa được thăm
        DFS(i,list,vis,st);//Duyệt DFS tại nút đó
    }

    st.push(s);// Đẩy nút đã thăm vào ngăn xếp stack
}
//Sắp xếp Topo
void TopoSort(vector <int> list[],int n)
{   bool vis[n];//Khai báo 1 biến thăm có giá trị true false

    stack <int> st;//Khai báo 1 ngăn xếp kiểu giá trị int

    for(int i=1;i<=n;i++)
        vis[i] = false;// Trước khi duyệt DFS, đánh dấu mọi nút là chưa được thăm

    for(int s=0;s<n;s++)
        if(!vis[s])
        DFS(s,list,vis,st);//Duyệt DFS tại mỗi đỉnh chưa được thăm
    //Xuat ra trật tự Topo
    while(!st.empty())//Nếu ngăn xếp không trống
    {
        cout<<st.top()<<" ";//Lấy ra đỉnh của ngăn xếp
        st.pop();//Xóa phần tử ở đầu stack
    }
}
int main()
{
    int n = 6;//So canh do thi
    vector <int> list[n];//Khai báo dãy vecto các cặp cạnh có hướng

    add(list, 1, 2);// thêm vao cặp cạnh có hướng từ đỉnh 1 dến 2
    add(list, 1, 3);// thêm vao cặp cạnh có hướng từ đỉnh 1 dến 3
    add(list, 2, 3);
    add(list, 2, 4);
    add(list, 3, 4);
    add(list, 3, 5);

    cout <<"Trat tu topo : ";
    TopoSort(list,n);

    return 0;
}
