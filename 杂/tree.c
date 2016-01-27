#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *left;
	struct Node *right;
}node, *pnode;

typedef struct Tree {
	pnode root;
}tree, *ptree;

pnode create_node(int data) {
	pnode New = (pnode)malloc(sizeof(node));
	if(!New)
		exit(1);
	New->data = data;
	New->left = NULL;
	New->right = NULL;
	return New;
}

ptree create_tree() {
	ptree New = (ptree)malloc(sizeof(tree));
	if(!New)
		exit(1);
	New->root = NULL;
	return New;
}

pnode add1_node(pnode root, pnode New) {
	if(!root)
		root = New;
	else if(New->data < root->data)
		root->left = add1_node(root->left, New);
	else
		root->right = add1_node(root->right, New);
	return root;
}

void add_node(ptree t, int data) {
	pnode New = create_node(data);
	t->root = add1_node(t->root, New);
}
// 中序遍历
// 递归
void fun1(pnode p) {
	if(!p)
		return ;
	fun1(p->left);
	printf("%d ", p->data);
	fun1(p->right);
}

void view1_tree(ptree t) {
	pnode p = t->root;
	fun1(p);
	printf("\n");
}
//非递归
void View1_tree(ptree t) {
	pnode p = t->root;
	pnode s[100];
	int top = 0;
	while(p || top) {
		while(p) {
			s[top++] = p;
			p = p->left;
		}
		if(top) {
			p = s[--top];
			printf("%d ", p->data);
			p = p->right;
		}
	}
	printf("\n");
}
// 前序遍历
// 递归
void fun2(pnode p) {
	if(!p)
		return ;
	printf("%d ", p->data);
	fun2(p->left);
	fun2(p->right);
}

void view2_tree(ptree t) {
	pnode p = t->root;
	fun2(p);
	printf("\n");
}
// 非递归
void View2_tree(ptree t) {
	pnode p = t->root;
	pnode s[100];
	int top = 0;
	while(top || p) {
		while(p) {
			printf("%d ", p->data);
			s[top++] = p;
			p = p->left;
		}
		if(top) {
			p = s[--top];
			p = p->right;
		}
	}
	printf("\n");
}

// 后序遍历
// 递归
void fun3(pnode p) {
	if(!p)
		return ;
	fun3(p->left);
	fun3(p->right);
	printf("%d ", p->data);
}

void view3_tree(ptree t) {
	pnode p = t->root;
	fun3(p);
	printf("\n");
}
// 非递归
void View3_tree(ptree t) {
	pnode p = t->root;
	pnode cur, pre;
	cur = pre = NULL;
	pnode s[100];
	int top = 0;
	if(t->root)
		s[top++] = t->root;
	while(top) {
		cur = s[top - 1];
		if((cur->left == NULL && cur->right == NULL) || (pre && (pre == cur->left || pre == cur->right))) {
			printf("%d ", cur->data);
			top--;
			pre = cur;
		}
		else {
			if(cur->right)
				s[top++] = cur->right;
			if(cur->left)
				s[top++] = cur->left;
		}
	}
	printf("\n");
}
// 层次遍历
void view4_tree(ptree t, int num) {
	pnode s[100];
	int ss[100];
	pnode p = t->root;
	if(!p)
		return ;
	int front = 0;
	int rear = 1;
	s[0] = p;
	ss[0] = 1;
	while(front < rear) {
		if(s[front]->left) {
			s[rear++] = s[front]->left;
			ss[rear - 1] = ss[front] + 1;
		}
		if(s[front]->right) {
			ss[rear] = ss[front] + 1;
			s[rear++] = s[front]->right;
		}
		if(ss[front] == num)
			printf("%d ", s[front]->data);
		if(num == 0) {
			printf("%d", s[front]->data);
			printf("(%d) ", ss[front]);
		}
		front++;
	}
	printf("\n");
}
// 镜像
void fun4(pnode p) {
	if(!p)
		return ;
	pnode temp;
	temp = p->left;
	p->left = p->right;
	p->right = temp;
	fun4(p->left);
	fun4(p->right);
}

void mirror(ptree t) {
	pnode p = t->root;
	fun4(p);
}
// 求最远距离
int Max;
int fun5(pnode p) {
	int l_max, r_max;
	if(!p)
		return 0;
	if(!p->left)
		l_max = 0;
	else
		l_max = fun5(p->left) + 1;
	if(!p->right)
		r_max = 0;
	else
		r_max = fun5(p->right) + 1;
	if(Max < l_max + r_max)
		Max = l_max + r_max;
	return l_max > r_max ? l_max : r_max;
}

int get_farthest(ptree t) {
	fun5(t->root);
	return Max;
}
// 求规定路径
void fun6(pnode p, int num, int cur, int total) {
	static pnode s[100];
	int i;
	s[cur] = p;
	num += p->data;
	if(p->left)
		fun6(p->left, num, cur + 1, total);
	if(p->right)
		fun6(p->right, num, cur + 1, total);
	if(!p->left && !p->right) {
		if(num == total) {
		for(i = 0; i <= cur; i++) {
			printf("%d", s[i]->data);
			if(i < cur)
				printf("->");
			}
		printf("\n");
		}
		else 
			return ;
	}
}

void get_route(ptree t, int total) {
	fun6(t->root, 0, 0, total);
}
// 公共父结点
pnode search_node(ptree t, int a) {
	pnode s[100];
	pnode p = t->root;
	int top = 0;
	while(top || p) {
		while(p) {
			if(p->data == a)
				return p;
			s[top++] = p;
			p = p->left;
		}
		if(top) {
			p = s[--top];
			p = p->right;
		}
	}
	return NULL;
}

pnode fun7(ptree t, pnode p, int a, int b) {
	if(p == NULL)
		return NULL;
	if(search_node(t, a) == NULL || search_node(t, b) == NULL)
		return NULL;
	if(p == search_node(t, a) || p == search_node(t, b))
		return p;
	pnode left = fun7(t, p->left, a, b);
	pnode right = fun7(t, p->right, a, b);
	if(left && right)
		return p;
	return left ? left : right;
}

void get_parent(ptree t, int a, int b) {
	pnode p = fun7(t, t->root, a, b);
	if(p == NULL)
		printf("Error!\n");
	else
		printf("the father is %d\n", p->data);
}
int main() {
	ptree t = NULL;
	int Switch = 1;
	while(Switch) {
		system("clear");
		printf("1 -- 创建二叉树 2 -- 添加结点 3 -- 先序遍历 4 -- 中序遍历 5 -- 后序遍历 6 -- 层次遍历 7 -- 镜像转换 8 -- 最远距离 9 -- 公共父结点 10 -- 特定路径 0 -- 退出\n");
		scanf("%d", &Switch);
		switch(Switch){
			case 1:{
					   if(t) {
						   printf("二叉树已存在，是否重新创建（1 -- 是  0 -- 否）");
						   int flag = 0;
						   scanf("%d", &flag);
						   if(flag)
							   t = create_tree();
					   }
					   else
						   t = create_tree();
					   break;
				   }
			case 2:{
					   printf("请输入要添加结点的值\n");
					   int data;
					   scanf("%d", &data);
					   add_node(t, data);
					   break;
				   }
			case 3:{
					   View2_tree(t);
					   view2_tree(t);
					   break;
				   }
			case 4:{
					   View1_tree(t);
					   view1_tree(t);
					   break;
				   }
			case 5:{
					   View3_tree(t);
					   view3_tree(t);
					   break;
				   }
			case 6:{
					   printf("请输入要输出的结点层数（0 -- 全部输出）");
					   int num;
					   scanf("%d", &num);
					   view4_tree(t, num);
					   break;
				   }
			case 7:{
					   mirror(t);
					   break;
				   }
			case 8:{
					   printf("the result is %d\n", get_farthest(t));
					   break;
				   }
			case 9:{
					   int num1, num2;
					   printf("请输入两个结点值\n");
					   scanf("%d%d", &num1, &num2);
					   get_parent(t, num1, num2);
					   break;
				   }
			case 10:{
						int sum;
						printf("请输入路径之和\n");
						scanf("%d", &sum);
						get_route(t, sum);
						break;
					}
		}
		getchar();
		getchar();
	}
	return 0;
}
