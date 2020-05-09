#include <bits/stdc++.h>
using namespace std;

template <typename Value, typename Tag>
class SegmentTreeNode {
 public:
  // [l, r)
  int l, r;
  Value val;
  Tag tag;
};

template <typename Value, typename Tag, Value (*merge)(Value, Value),
          void (*update)(SegmentTreeNode<Value, Tag>&, Tag)>
class SegmentTree {
 private:
  std::vector<SegmentTreeNode<Value, Tag>> nodes;
  // segment: [leftRange, rightRange)
  int leftRange, rightRange;
  Value valueZero;
  Tag tagZero;

  inline int left(int cur) { return 2 * cur + 1; }
  inline int right(int cur) { return 2 * cur + 2; }

  void pushup(int cur) {
    nodes[cur].val = merge(nodes[left(cur)].val, nodes[right(cur)].val);
  }

  void pushdown(int cur) {
    update(nodes[left(cur)], nodes[cur].tag);
    update(nodes[right(cur)], nodes[cur].tag);
    nodes[cur].tag = tagZero;
  }

  void build(int cur, int l, int r, const std::vector<Value>& a) {
    nodes[cur].l = l;
    nodes[cur].r = r;
    nodes[cur].tag = tagZero;
    if (l == r - 1)
      nodes[cur].val = a[l - leftRange];
    else {
      build(left(cur), l, (l + r) >> 1, a);
      build(right(cur), (l + r) >> 1, r, a);
      pushup(cur);
    }
  }

  void modify(int cur, int l, int r, int L, int R, const Tag& tag) {
    if (l >= R || r <= L) return;
    if (L <= l && r <= R)
      update(nodes[cur], tag);
    else {
      pushdown(cur);
      modify(left(cur), l, (l + r) >> 1, L, R, tag);
      modify(right(cur), (l + r) >> 1, r, L, R, tag);
      pushup(cur);
    }
  }

  Value query(int cur, int l, int r, int L, int R) {
    if (l >= R || r <= L) return valueZero;
    if (L <= l && r <= R) return nodes[cur].val;
    pushdown(cur);
    return merge(query(left(cur), l, (l + r) >> 1, L, R),
                 query(right(cur), (l + r) >> 1, r, L, R));
  }

 public:
  /**
   * use a[0, rightRange - leftRange) to init semgent: [leftRange, rightRange)
   */
  SegmentTree(const Value& _valueZero, const Tag& _tagZero, int _leftRange,
              int _rightRange, const std::vector<Value>& a) {
    leftRange = _leftRange;
    rightRange = _rightRange;
    valueZero = _valueZero;
    tagZero = _tagZero;
    nodes.resize((rightRange - leftRange) << 2);
    build(0, leftRange, rightRange, a);
  }

  void modify(int l, int r, const Tag& tag) {
    modify(0, leftRange, rightRange, l, r, tag);
  }

  void modify(int p, const Tag& tag) { modify(p, p + 1, tag); }

  Value query(int l, int r) { return query(0, leftRange, rightRange, l, r); }

  Value query(int p) { return query(p, p + 1); }
};

// all code are copied from
// https://github.com/ouuan/segmentTree/blob/master/segmenttree.h
struct Tag {
  int add, mul;
  Tag(int _add = 0, int _mul = 1) {
    add = _add;
    mul = _mul;
  }
  void operator+=(const Tag& y) {
    add = add * y.mul + y.add;
    mul = mul * y.mul;
  }
};

using Value = int;
Value merge(Value x, Value y) { return x + y; }

void update(SegmentTreeNode<Value, Tag>& node, Tag tag) {
  node.val = node.val * tag.mul + tag.add * (node.r - node.l);
  node.tag += tag;
}

int main() {
  vector<Value> a(3, 0);
  SegmentTree<Value, Tag, merge, update> t(0, Tag(), 0, 3, a);
}
