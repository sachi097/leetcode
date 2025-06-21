class ThroneInheritance {
    HashMap<String, List<String>> inherintanceAdjList;
    HashSet<String> deathSet;
    String root;
    public ThroneInheritance(String kingName) {
        this.root = kingName;
        this.deathSet = new HashSet<>();
        this.inherintanceAdjList = new HashMap<>();
        this.inherintanceAdjList.putIfAbsent(kingName, new ArrayList<>());
    }
    
    public void birth(String parentName, String childName) {
        this.inherintanceAdjList.get(parentName).add(childName);
        this.inherintanceAdjList.putIfAbsent(childName, new ArrayList<>());
    }
    
    public void death(String name) {
        this.deathSet.add(name);
    }
    
    public List<String> getInheritanceOrder() {
        List<String> answer = new ArrayList<>();
        HashSet<String> visited = new HashSet<>();
        dfs(this.root, visited, answer);
        return answer;
    }

    private void dfs(String parent, HashSet<String> visited, List<String> answer){
        if(!visited.contains(parent)){
            visited.add(parent);
            if(!deathSet.contains(parent)){
                answer.add(parent);
            }
            for(String child: this.inherintanceAdjList.get(parent)){
                dfs(child, visited, answer);
            }
        }
    }
}

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance obj = new ThroneInheritance(kingName);
 * obj.birth(parentName,childName);
 * obj.death(name);
 * List<String> param_3 = obj.getInheritanceOrder();
 */