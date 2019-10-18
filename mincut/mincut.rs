use std::io::{self, BufRead, Error};
use std::str::FromStr;
use std::collections::VecDeque;
use std::usize::{MAX};

fn one(ls: &mut std::io::Lines<std::io::StdinLock>) -> Result<String, Error> {
  ls.next().unwrap()
}

fn line<T>(line: Result<String, Error>) -> Vec<T>
where
  T: FromStr,
  T::Err: std::fmt::Debug,
{
  line.unwrap()
    .split(" ")
    .map(|x| x.parse::<T>().unwrap())
    .collect()
}

fn three_from<T: Copy>(v: Vec<T>) -> (T, T, T) {
  (v[0], v[1], v[2])
}

fn four_from<T: Copy>(v: Vec<T>) -> (T, T, T, T) {
  (v[0], v[1], v[2], v[3])
}

type Graph = [[usize; 500]; 500];

fn main() {
  let stdin = io::stdin();
  let mut ls = stdin.lock().lines();

  let (n, _m, s, t) = four_from(line::<usize>(one(&mut ls)));
  let mut g: Graph = [[0; 500]; 500];
  for l in ls {
    let (v, w, c) = three_from(line::<usize>(l));
    g[v][w] = c;
  }

  loop {
    match dfs(g, n, s, t) {
      None => break,
      Some(parents) => {
        let mut flow = MAX;
        let mut v = parents[t];
        let mut w = t;
        while w != s {
          flow = usize::min(flow, g[v][w]);
          w = v;
          v = parents[v];
        }

        v = parents[t];
        w = t;
        while w != s {
          g[v][w] -= flow;
          g[w][v] += flow;
          w = v;
          v = parents[v];
        }
      },
    };
  }

  let us_seen = bfs(g, n, s);
  let mut us = Vec::new();
  for v in 0 .. n {
    if us_seen[v] {
      us.push(v);
    }
  }
  println!("{}", us.len());
  for v in us {
    println!("{}", v);
  }
}

fn dfs(g: Graph, n: usize, s: usize, t: usize) -> Option<[usize; 500]> {
  let mut stack = Vec::new();
  stack.push(s);
  let mut seen = [false; 500];
  let mut parents = [MAX; 500];
  let mut pv = s;
  while stack.len() > 0 {
    let v = stack.pop().unwrap();
    seen[v] = true;
    parents[v] = pv;
    pv = v;
    if v == t {
      break
    }
    for w in 0 .. n {
      let c = g[v][w];
      if c > 0 && !seen[w] {
        stack.push(w);
      }
    }
  };
  if parents[t] < MAX {
    Some(parents)
  } else {
    None
  }
}

fn bfs(g: Graph, n: usize, s: usize) -> [bool; 500] {
  let mut queue = VecDeque::new();
  queue.push_back(s);
  let mut seen = [false; 500];
  while queue.len() > 0 {
    let v = queue.pop_front().unwrap();
    seen[v] = true;
    for w in 0 .. n {
      let c = g[v][w];
      if c > 0 && !seen[w] {
        queue.push_back(w);
      }
    }
  };
  seen
}
