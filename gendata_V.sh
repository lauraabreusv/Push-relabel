#!/usr/bin/env bash
rm -f .Vdata
for i in $(seq 1000 100 10000)
do
  echo -ne "$i/10000\r"
  echo -e "$i\n10000" | python create_random_graph.py > .graph
  start_time="$(date -u +%s.%N)"
  cat .graph | ./pr > /dev/null
  end_time="$(date -u +%s.%N)"
  elapsed="$(bc <<<"$end_time-$start_time")"
  echo $elapsed >> .Vdata
done
