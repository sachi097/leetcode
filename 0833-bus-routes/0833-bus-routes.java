class Solution {
    public int numBusesToDestination(int[][] routes, int source, int target) {

        if(source == target){
            return 0;
        }

        HashMap<Integer, ArrayList<Integer>> busMap = new HashMap<>();
        for(int i=0; i<routes.length; i++){
            int[] route = routes[i];
            for(int j=0; j<route.length; j++){
                int u = route[j];
                busMap.computeIfAbsent(u, k -> new ArrayList<>()).add(i);
            }
        }


        Queue<Integer> q = new ArrayDeque<>();
        HashSet<Integer> visited = new HashSet<>();
        ArrayList<Integer> sourceBuses = busMap.getOrDefault(source, new ArrayList<>());
        for(int bus: sourceBuses){
            q.add(bus);
            visited.add(bus);
        }

        int level = 1;
        while(!q.isEmpty()){
            int size = q.size();
            for(int s=0; s<size; s++){
                int currentBus = q.poll();
                int[] currentRoute = routes[currentBus];
                for(int route: currentRoute){
                    if(route == target){
                        return level;
                    }
                    sourceBuses = busMap.getOrDefault(route, new ArrayList<>());
                    for(int bus: sourceBuses){
                        if(!visited.contains(bus)){
                            q.add(bus);
                            visited.add(bus);
                        }
                    }
                }
            }
            level++;
        }

        return -1;

    }
}