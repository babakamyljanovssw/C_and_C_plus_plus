#include <stdio.h>
#include <stdlib.h>

#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1

struct TreeNode{
	ElementType Element;	//Elements of Nodes
	Tree Left;				//Left child position
	Tree Right;				//Right child position
}T1[MaxTree],T2[MaxTree];	//Define two arrays of MaxTree size
	

Tree BuildTree( struct TreeNode T[] )
{
	Tree Root;
	int N,i;
	int *check;
	char cl,cr;
	scanf("%d\n", &N);	//Read in an integer N
	check=(int*)malloc(N*sizeof(int));
	if(N) {				//N is not zero, continue reading data
		for (int i=0;i<N;i++)
			check[i] = 0;	//check for each node is set to 0
		for (i=0;i<N;i++){	//Read in the information of N nodes
			scanf("%c %c %c\n", &T[i].Element, &cl, &cr);
			if (cl!='-'){				//cl is not - - that means there's a left son.
				T[i].Left = cl-'0';		//The cl read in is a character, - '0' gives an integer.
				check[T[i].Left] = 1;	//check of a node pointed to by another node is set to 1
			}else {
				T[i].Left = Null;		//cl is -, which means there is no left son.
			}
			if (cr!='-'){
				T[i].Right = cr-'0';
				check[T[i].Right] = 1;
			}else
				T[i].Right = Null;
		}
		for (i=0;i<N;i++)
			if (!check[i])	//The node where check is still zero is the root node.
				break;
		Root = i;
	}else{
		return Null;
	}
	return Root;		//Return to the root node
}

int Isomorphic ( Tree R1, Tree R2 )
{
 if ((R1==Null)&&(R2==Null)) /* Two empty trees are isomorphic */
	return 1;
 if (((R1==Null)&&(R2!=Null))||((R1!=Null)&&(R2==Null)))
	return 0; /* One of the empty trees must have different structures. */
 if (T1[R1].Element!=T2[R2].Element)
	return 0; /* Different root nodes and different structures */
 if (( T1[R1].Left==Null)&&( T2[R2].Left==Null))
	/* If the left subtree is empty, the right subtree is isomorphic. */
	return Isomorphic(T1[R1].Right,T2[R2].Right);
 if (((T1[R1].Left!=Null)&&(T2[R2].Left!=Null))&&((T1[T1[R1].Left].Element)==(T2[T2[R2].Left].Element)))
	/* If the left subtree is not empty and the left element is the same, the left subtree is isomorphic or the right subtree is isomorphic.*/
	return (Isomorphic( T1[R1].Left, T2[R2].Left ) && Isomorphic( T1[R1].Right, T2[R2].Right));

 else /* Discrimination of Left and Right Isomorphism */
	return (Isomorphic( T1[R1].Left, T2[R2].Right) && Isomorphic( T1[R1].Right, T2[R2].Left));

}

int main()
{
	Tree R1,R2;
	 //Building Binary Tree 1
	R1=BuildTree(T1);
	 //Building Binary Tree 2
	R2=BuildTree(T2);
	 //Identify isomorphism and output
	if(Isomorphic(R1,R2))
		printf("Yes\n");
	else
		printf("No\n");
	 return 0;
}