/*
SQRT decomposition on array queries
*/

bool cmp(Query A, Query B){
  if (A.l / S != B.l / S) return A.l < B.l;
  return A.l / S % 2 ? A.r > B.r : A.r < B.r;
}


for(int i = 0; i < q; i++){
  Query qe = qris[i];
  while(r < qe.r){
    r++;
    add(r);
  }
  while(r > qe.r){
    dlt(r);
    r--;
  }
  while(l < qe.l){
    dlt(l);
    l++;
  }
  while(l > qe.l){
    l--;
    add(l);
  }
  answ[qe.id] = ans;
}
