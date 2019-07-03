#!/usr/bin/env bash
rm .Edata
for i in $(seq 1000 100 10000)
do
  echo -e "$i\r"
  echo -e "1000\n$i" | python create_random_graph.py > .graph
  start_time="$(date -u +%s.%N)"
  cat .graph | ./a.out > /dev/null
  end_time="$(date -u +%s.%N)"
  elapsed="$(bc <<<"$end_time-$start_time")"
  echo $elapsed >> .Edata
done
