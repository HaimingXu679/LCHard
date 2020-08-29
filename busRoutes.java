// https://leetcode.com/problems/bus-routes/

// Simple BFS

// O(N^2), beats 40%

import java.awt.Point;

class Solution {
    public int numBusesToDestination(int[][] routes, int S, int T) {
        if (S == T)
            return 0;
        HashMap<Integer, HashSet<Integer> > connect = new HashMap<>(), graph = new HashMap<>();
        for (int i = 0; i < routes.length; i++) {
            for (int j = 0; j < routes[i].length; j++) {
                if (connect.containsKey(routes[i][j]))
                    connect.get(routes[i][j]).add(i);
                else {
                    HashSet<Integer> temp = new HashSet<>();
                    temp.add(i);
                    connect.put(routes[i][j], temp);
                }
            }
        }
        HashSet<Integer> seen = new HashSet<>(), goals = new HashSet<>();
        Queue<Point> v = new ArrayDeque<>();
        for (Integer node : connect.keySet()) {
            Iterator<Integer> it = connect.get(node).iterator();
            while (it.hasNext()) {
                int current = it.next();
                if (graph.containsKey(current))
                    graph.get(current).addAll(connect.get(node));
                else {
                    HashSet<Integer> temp = new HashSet<>();
                    temp.addAll(connect.get(node));
                    graph.put(current, temp);
                }
                if (node == S) {

                    v.offer(new Point(current, 0));
                    seen.add(current);
                } else if (node == T)
                    goals.add(current);
            }
        }
        while (v.size() > 0) {
            Point temp = v.poll();
            if (goals.contains(temp.x))
                return temp.y + 1;
            seen.add(temp.x);
            for (Integer next : graph.get(temp.x)) {
                if (!seen.contains(next))
                    v.offer(new Point(next, temp.y + 1));
            }
        }
        return -1;
    }
}
