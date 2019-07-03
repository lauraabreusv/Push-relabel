#!/usr/bin/env bash
rm -f .Vdata
for i in $(seq 100 100 3000)
do
  echo -ne "$i/3000\r"
  echo -e "$i\n4000" | python create_random_graph.py > .graph
  start_time="$(date -u +%s.%N)"
  cat .graph | ./pr > /dev/null
  end_time="$(date -u +%s.%N)"
  elapsed="$(bc <<<"$end_time-$start_time")"
  echo $elapsed >> .Vdata
done
