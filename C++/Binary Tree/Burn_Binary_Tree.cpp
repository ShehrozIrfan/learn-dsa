#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,x,y) for(ll i=x;i<y;i++)


class Node
{
public:
    int data;
    Node* left=NULL;
    Node* right=NULL;
    Node(int x)
    {
        data=x;
    }
};

void PreOrder(Node* head, vector<int> &a)
{
    if(head==NULL) return;
    a.push_back(head->data);
    PreOrder(head->left,a);
    PreOrder(head->right,a);
    return;
}

void InOrder(Node* head, vector<int> &a)
{
    if(head==NULL) return;
    InOrder(head->left,a);
    a.push_back(head->data);
    InOrder(head->right,a);
    return;
}

void PostOrder(Node* head, vector<int> &a)
{
    if(head==NULL) return;
    PostOrder(head->left,a);
    PostOrder(head->right,a);
    a.push_back(head->data);
    return;
}


void ZigZag(Node* head, vector<vector<int>> &a, int level, int ltr)
{
    queue<Node*> q;
    q.push(head);
    q.push(NULL);
    while(!q.empty())
    {
        if(q.front()==NULL)
        {
            q.pop();
            if(!q.empty()) q.push(NULL);
            if(ltr==-1) {
                reverse(a[level].begin(),a[level].end());
                level++;
                ltr=1;
            }
            else if(ltr==1) ltr=-1,level++;
        }
        if(q.front()!=NULL) {
            a[level].push_back(q.front()->data);
            if(q.front()->left!=NULL) q.push(q.front()->left);
            if(q.front()->right!=NULL) q.push(q.front()->right);
            q.pop();
        }
    }
    return;
}


int height(Node* head)
{
    if(head==NULL) return 0;
    int lh=height(head->left);
    int rh=height(head->right);
    return max(lh,rh)+1;
}

bool CheckBalanced(Node* head)
{
    if(head==NULL) return true;
    if(abs(height(head->left)-height(head->right))>1) return false;
    return CheckBalanced(head->left)&&CheckBalanced(head->right);
}

int Diameter(Node* head)
{
    if(head==NULL) return 0;
    return max(height(head->left)+height(head->right)+1,max(Diameter(head->left),Diameter(head->right)));
}

int MaxPathSum(Node* head, int &maxi)
{
    if(head==NULL) return 0;
    int x=MaxPathSum(head->left, maxi)+MaxPathSum(head->right, maxi)+head->data;
    int y=max(MaxPathSum(head->left, maxi),MaxPathSum(head->right, maxi))+head->data;
    maxi=max(maxi, x);
    return y;
}

void VerticalOrder(Node* head, map<int,vector<int>> &a,int x,int y) {
    if(head==NULL) return;
    a[y].push_back(head->data);
    VerticalOrder(head->left,a,x+1,y-1);
    VerticalOrder(head->right,a,x+1,y+1);
    return;
}

void TopView(Node* head, map<int,int> &a, int y)
{
// Level Order Traversal must be used
// Recursive Method is wrong here as it will give wrong output for:
    /*
               1
              / \
             2   3
            /    /
           4    6
            \
             5
              \
               7
                \
                 8

         it will give 8 instead of 3.
    */
    if(head==NULL) return;
    if(a[y]==0) a[y]=head->data;
    if(head->left!=NULL) TopView(head->left,a,y-1);
    if(head->right!=NULL) TopView(head->right,a,y+1);
    return;
}

void BottomView(Node* head,map<int,int> &a, int y)
{
// Level Order Traversal must be used
// Recursive Method is wrong here as it will give wrong output for:
    /*
               1
              / \
             2   3
            /    /
           4    6
            \
             5
              \
               7

         it will give 6 instead of 7.
    */
    if(head==NULL) return;
    a[y]=head->data;
    BottomView(head->left,a,y-1);
    BottomView(head->right,a,y+1);
    return;
}

void LeftView(Node* head, vector<int> &a)
{
    if(head==NULL) return;
    queue<Node*> q;
    q.push(head);
    q.push(NULL);
    a.push_back(head->data);
    int level=1;
    while(!q.empty())
    {
        if(q.front()==NULL)
        {
            q.pop();
            if(!q.empty()) q.push(NULL);
            level++;
            if(!q.empty() && a.size()<level) a.push_back(q.front()->data);
        }
        else
        {
            if(q.front()->left!=NULL) q.push(q.front()->left);
            if(q.front()->right!=NULL) q.push(q.front()->right);
            q.pop();
        }
    }
}

void RightView(Node* head, vector<int> &a)
{
    if(head==NULL) return;
    queue<Node*> q;
    q.push(head);
    q.push(NULL);
    int level=1;
    a.push_back(head->data);
    while(!q.empty())
    {
        if(q.front()==NULL)
        {
            q.pop();
            if(!q.empty()) q.push(NULL);
            level++;
            if(!q.empty() && a.size()<level) a.push_back(q.front()->data);
        }

        else {
            if(q.front()->right!=NULL) q.push(q.front()->right);
            if(q.front()->left!=NULL) q.push(q.front()->left);
            q.pop();
        }
    }
}

bool Find(Node* head, int a, int b)
{
    if(head==NULL) return false;
    if(head->data==a || head->data==b) return true;
    else return Find(head->left,a,b)||Find(head->right,a,b);
}

int LowestCommonAncestor(Node* head,int a,int b)
{
    if(head==NULL) return -1;
    if(head->data==a || head->data==b) return head->data;
    else if(Find(head->left,a,b) && Find(head->right,a,b)) return head->data;
    else if(Find(head->left,a,b)) return LowestCommonAncestor(head->left,a,b);
    else if(Find(head->right,a,b)) return LowestCommonAncestor(head->right,a,b);
    return -1;
}

void ParentNode(Node* head,map<Node*,Node*> &parent)
{
    if(head==NULL) return;
    if(head->left)
    {
        parent[head->left]=head;
        ParentNode(head->left,parent);
    }
    if(head->right)
    {
        parent[head->right]=head;
        ParentNode(head->right,parent);
    }
    return;
}

void ChildrenSumProperty(Node* head)
{
    if(head==NULL) return;
    if(head->left && head->right && head->left->data+head->right->data<=head->data)
    {
        head->left->data=head->data;
        head->right->data=head->data;
        ChildrenSumProperty(head->left);
        ChildrenSumProperty(head->right);
        head->data=head->left->data+head->right->data;
        return;
    }
    else if(head->right && !head->left && head->right->data<=head->data)
    {
        head->right->data=head->data;
        ChildrenSumProperty (head->right);
        head->data=head->right->data;
    }
    else if(head->right && !head->left && head->right->data > head->data)
    {
        ChildrenSumProperty (head->right);
        head->data=head->right->data;
    }
    else if(head->left && !head->right && head->left->data<=head->data)
    {
        head->left->data=head->data;
        ChildrenSumProperty (head->left);
        head->data=head->left->data;
    }
    else if(head->left && !head->right && head->left->data > head->data)
    {
        ChildrenSumProperty (head->left);
        head->data=head->left->data;
    }
    else if(head->left && head->right)
    {
        head->data=head->left->data+head->right->data;
        ChildrenSumProperty(head->left);
        ChildrenSumProperty(head->right);
        head->data=head->left->data+head->right->data;
    }
    return;
}

void BurnTree(Node* head, int &ans, map<Node*,int> &vis, map<Node*,Node*> parent)
{
    if(head==NULL) return;
    int ansleft=ans,ansright=ans,ansparent=ans;
    if(head->left && vis[head->left]==0)
    {
        vis[head->left]=1;
        ansleft+=1;
        BurnTree(head->left,ansleft,vis,parent);
    }
    if(head->right && vis[head->right]==0)
    {
        vis[head->right]=1;
        ansright+=1;
        BurnTree(head->right,ansright,vis,parent);
    }
    if(parent[head]!=NULL && vis[parent[head]]==0)
    {
        vis[parent[head]]=1;
        ansparent+=1;
        BurnTree(parent[head],ansparent,vis,parent);
    }
    ans=max(ansparent,max(ansleft,ansright));
    return;
}

int main()
{
    Node* head=new Node(1);
    head->left=new Node(2);
    head->right=new Node(3);
    head->left->left=new Node(4);
    head->left->right=new Node(5);
    head->right->left=new Node(6);
    head->right->right=new Node(7);
    head->left->left->right=new Node(8);
    head->left->right->left=new Node(9);
    head->right->left->left=new Node(10);
    head->right->right->right=new Node(11);
    head->right->right->right->right=new Node(12);

    
        vector<int> pre,in,post;
        PreOrder(head,pre);
        InOrder(head,in);
        PostOrder(head,post);
        cout<<"\nPreOrder: ";
        for(int i=0; i<pre.size(); i++)
        {
            cout<<pre[i]<<' ';
        }/*
        cout<<"\nInOrder: ";
        cout<<'\n';
        for(int i=0; i<in.size(); i++)
        {
            cout<<in[i]<<' ';
        }
        cout<<'\n';
        cout<<"\nPostOrder: ";
        for(int i=0; i<post.size(); i++)
        {
            cout<<post[i]<<' ';
        }
        cout<<'\n';

        cout<<"\nHeight: ";
        int h=height(head);
        cout<<h<<'\n';

        cout<<"\nIs Balanced: ";
        bool balanced=CheckBalanced(head);
        cout<<balanced;

        cout<<"\nDiameter:\n";
        int d = Diameter(head);
        cout<<d;

        cout<<"\nMax Path Sum:\n";
        int maxi=0;
        int maxpathsum=MaxPathSum(head,maxi);
        cout<<max(maxi, maxpathsum);

        cout<<"\nZigZag Order:\n";
        vector<vector<int>> zigzag(height(head));
        ZigZag(head,zigzag,1,1);
        for(int i=0; i<=zigzag.size(); i++)
        {
            for(int j=0; j<zigzag[i].size(); j++)
            {
                cout<<zigzag[i][j]<<" ";
            }
            cout<<endl;
        }

        cout<<"\nVertical Order:\n";
        map<int,vector<int>> v;
        VerticalOrder(head,v,0,0);
        for(auto i=v.begin(); i!=v.end(); i++) {
            for(auto j=i->second.begin(); j!=i->second.end(); j++) {
                cout<<*j<< ' ';
            }
            cout<<endl;
        }

        cout<<"\nTop View:\n";
        map<int,int> topv;
        TopView(head, topv, 0);
        for(map<int,int>::iterator i=topv.begin(); i!=topv.end(); i++)
            cout<<i->second<<" ";
        cout<<endl;

        cout<<"\nBottom View:\n";
        map<int,int> bottomv;
        BottomView(head, bottomv, 0);
        for(map<int,int>::iterator i=bottomv.begin();i!=bottomv.end();i++)
        {
        cout<<i->second<<" ";
        }
        cout<<endl;

        cout<<"\nLeft View:\n";
        vector<int> leftv;
        LeftView(head,leftv);
        for(int i=0; i<leftv.size(); i++) cout<<leftv[i]<<" ";
        cout<<endl;

        cout<<"\nRight View:\n";
        vector<int> rightv;
        RightView(head,rightv);
        for(int i=0; i<rightv.size(); i++) cout<<rightv[i]<<" ";
        cout<<endl;

        int n1=3,n2=11;
        int lcs=LowestCommonAncestor(head,n1,n2);
        cout<<"\nLowest Common Ancestor of "<<n1<<" and "<<n2<<" is: ";
        cout<<lcs<<endl;

        cout<<"\nChildren Sum Property:\n";
        ChildrenSumProperty(head);
        cout<<"\nZigZag Order:\n";
        vector<vector<int>> zigzag(height(head));
        ZigZag(head,zigzag,1,1);
        for(int i=0; i<=zigzag.size(); i++)
        {
            for(int j=0; j<zigzag[i].size(); j++)
            {
                cout<<zigzag[i][j]<<" ";
            }
            cout<<endl;
        }
    
        map<Node*,Node*> parent;
        ParentNode(head,parent);
        parent[head]=NULL;
        map<Node*,int> vis;
        Node* start=head->left->right;
        vis[start]=1;
        int ans=0;
        BurnTree(start,ans,vis,parent);
        cout<<ans<<"\n";
        string s="mathwprls";
        for(;s!='\0';s++)
        {
        printf("%c",s);
    }
    */
   cout<<"\nZigZag Order:\n";
        vector<vector<int>> zigzag(height(head));
        ZigZag(head,zigzag,1,1);
        for(int i=0; i<=zigzag.size(); i++)
        {
            for(int j=0; j<zigzag[i].size(); j++)
            {
                cout<<zigzag[i][j]<<" ";
            }
            cout<<endl;
        }
    return 0;
}