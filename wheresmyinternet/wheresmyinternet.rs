use std::io::{self, BufRead};
use std::collections::HashSet;

type Graph = Vec<HashSet<usize>>;

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();

    let first_line = lines.next();
    let first_line_input = first_line.unwrap().unwrap();
    let nodes_and_edges: Vec<&str> = first_line_input.split(' ').collect();

    let node_count: usize = nodes_and_edges[0].parse().unwrap();
    let _edge_count: usize = nodes_and_edges[1].parse().unwrap();

    let mut graph: Graph = Vec::new();
    let mut nodes = HashSet::new();
    for index in 0 .. node_count {
        graph.push(HashSet::new());
        nodes.insert(index);
    }
    
    for line in lines {
        let input = line.unwrap();
        let edge: Vec<&str> = input.split(' ').collect();
        let from: usize = edge[0].parse().unwrap();
        let to: usize = edge[1].parse().unwrap();
        graph[from - 1].insert(to - 1);
        graph[to - 1].insert(from - 1);
    }

    let connected = dfs(graph, 0);
    let mut unconnected: Vec<_> = nodes.difference(&connected).collect();
    if unconnected.len() == 0 {
        println!("Connected");
    } else {
        unconnected.sort();
        for node in unconnected {
            println!("{}", node + 1);
        }
    }
}

fn dfs(graph: Graph, start_node: usize) -> HashSet<usize> {
    let mut seen: HashSet<usize> = HashSet::new();
    let mut remaining: Vec<usize> = Vec::new();
    seen.insert(start_node);
    remaining.push(start_node);
    while remaining.len() > 0 {
        let curr = remaining.pop().unwrap();
        let next_nodes = &graph[curr];
        for next in next_nodes.iter() {
            if !seen.contains(next) {
                seen.insert(*next);
                remaining.push(*next);
            }
        }
    }
    return seen;
}