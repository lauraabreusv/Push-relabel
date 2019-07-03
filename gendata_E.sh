#!/usr/bin/env bash
rm -f .Edata
for i in $(seq 1000 1000 100000)
do
  echo -en "$i/100000\r"
  echo -e "1000\n$i" | python create_random_graph.py > .graph
  start_time="$(date -u +%s.%N)"
  cat .graph | ./pr > /dev/null
  end_time="$(date -u +%s.%N)"
  elapsed="$(bc <<<"$end_time-$start_time")"
  echo $elapsed >> .Edata;
done;
