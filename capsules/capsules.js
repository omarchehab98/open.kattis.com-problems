const lines = [];
require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
  terminal: false
}).on('line', (line) => {
  lines.push(line);
}).on('close', () => {
  const [r, c] = lines.shift().split(' ').map(Number);
  const grid = [];
  for (let m = 0; m < r; m++) {
    grid.push(lines.shift().split(' ').map(x => x != '-' ? Number(x) : null));
  }
  const regions = [];
  const n = Number(lines.shift())
  for (let i = 0; i < n; i++) {
    regions.push(lines.shift().split(' ').slice(1).map(x => x.slice(1, -1).split(',').map(Number)));
  }
  console.log(capsules(r, c, grid, regions).map(x => x.map(y => y || '-').join(' ')).join('\n'))
});

function capsules(r, c, grid, regions) {
  // console.log(r, c, grid, regions)
  return grid;
}
