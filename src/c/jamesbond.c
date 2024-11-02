#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>

const double ISLAND_RADIUS = 15.0 / 2;
//const double SQUARE_SIZE = 100.0;
#define SIZE 110

void save007();
bool FirstJump(int v);
bool DFS(int v);
bool IsSave(int v);
bool Jump(int v1,int v2);
bool visit[SIZE];
int n;
double d;

typedef struct Point
{
    double x,y;
}Position;
Position P[SIZE];

bool Jump(int v1,int v2)
{
return sqrt((P[v1].x - P[v2].x)*(P[v1].x - P[v2].x) + (P[v1].y - P[v2].y) * (P[v1].y - P[v2].y)) <= d;
}

bool IsSave(int v)
{
    return (abs(P[v].x) >= 50 - d) || (abs(P[v].y) >= 50 - d);
}

bool DFS(int v)
{
    bool answer = false;
    visit[v] = true;
    if(IsSave(v))  return true;
    for(int i = 0; i < n; i++)
    {
        if(!visit[i] && Jump(v,i))
        {
            answer = DFS(i);
        }
        if(answer) break;
    }
    return answer;
}

bool FirstJump(int v)
{
    return sqrt(P[v].x * P[v].x + P[v].y * P[v].y) <= d + ISLAND_RADIUS;
}

void save007()
{
    bool IsVisit = false;
    for(int i = 0; i < n; i++)
    {
        if(!visit[i] && FirstJump(i))
        {
            IsVisit = DFS(i);
            if(IsVisit) break;
        }
    }
    if(IsVisit) printf("Yes\n");
    else printf("No\n");
}

int main()
{
  scanf("%d %lf",&n,&d);

  for(int i = 0 ; i < n; i++)
    scanf("%lf %lf",&(P[i].x),&(P[i].y));

  for(int i = 0 ; i < n; i++)
    visit[i] = false;

  save007();
  return 0;
}