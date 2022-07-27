//#pragma once
//#include <list>
//#include <map>
//#include <queue>
//#include "Point.h"
//using namespace std;
//
//
//class Graph {
//	map<Point, list<Point>> l;
//
//public:
//	void addEdge(Point p1, Point p2)
//	{
//		l[p1].push_back(p2);
//		l[p2].push_back(p1);
//	}
//
//	void bfs(Point src)
//	{
//		map<Point, bool> visited;
//		map<Point, int> dist;
//		//Set distance of to infiniti to all
//		for (auto j : l)
//		{
//			dist[j.first] = INT_MAX; //CHECK IF VALID!!!!!!
//		}
//		queue<Point> q;
//
//		//push the 'POINT' to the queue and makes it visited
//		q.push(src);
//		visited[src] = true;
//
//		while (q.empty()==false)
//		{
//			//save the 'POINT' and remove it
//			Point node_point = q.front();
//			q.pop();
//
//			//loop in the nighbors of the POINT
//			for (Point nbr : l[node_point])
//			{
//				if (visited[nbr] == false)
//				{
//					q.push(nbr);
//					//mark that nighbor as visited
//					visited[nbr] = true;
//				}
//			}
//		}
//	}
//};