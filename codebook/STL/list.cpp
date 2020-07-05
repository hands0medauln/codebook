list<T> l;
// push
l.push_front(1);
l.push_back(2);
// 1, 2
l.front() == 1;
l.back() == 2;
// pop
l.pop_back();
l.pop_front();
// insert
auto it = l.begin();
l.insert(it, num);
// find

// erase
l.erase(it);
l.erase(fr, to);
// other
l.clean();
l.size();
l.empty();
//
l.sort();
// 去除重複(先sort)
l.unique(/*binary predicate*/);

