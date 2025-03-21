class Solution {
    public List<String> findAllRecipes(String[] recipes, List<List<String>> ingredients, String[] supplies) {
        HashMap<String, List<String>> adj = new HashMap<>();
        HashMap<String, Integer> indegree = new HashMap<>();
        HashSet<String> supplierSet = new HashSet<>();
        HashSet<String> receipeSet = new HashSet<>();

        for(int i=0; i<supplies.length; i++){
            supplierSet.add(supplies[i]);
        }



        for(int i=0; i<recipes.length; i++){
            String v = recipes[i];
            receipeSet.add(v);
            indegree.put(v, 0);
            for(String u: ingredients.get(i)){
                indegree.put(u, 0);
            }
        }


        for(int i=0; i<recipes.length; i++){
            String v = recipes[i];
            for(String u: ingredients.get(i)){

                adj.computeIfAbsent(u, key -> new ArrayList<String>()).add(v);
                
                indegree.put(v, indegree.get(v) + 1);
            }
        }

        ArrayDeque<String> q = new ArrayDeque();

        for(Map.Entry<String, Integer> entry: indegree.entrySet()){
            if(entry.getValue() == 0 && supplierSet.contains(entry.getKey())){
                q.add(entry.getKey());
            }
        }

        List<String> ans = new ArrayList<>();

        while(!q.isEmpty()){
            String u = q.poll();
            if(adj.containsKey(u)){
                for(String v: adj.get(u)){
                    indegree.put(v, indegree.get(v) - 1);
                    if(indegree.get(v) == 0){
                        q.add(v);
                        if(receipeSet.contains(v)){
                            ans.add(v);
                        }
                    }
                }
            }
        }

        return ans;
    }
}