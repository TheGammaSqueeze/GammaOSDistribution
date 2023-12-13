use super::super::navigate;
use super::*;
use crate::fmt::Debug;
use crate::string::String;
use core::cmp::Ordering::*;

impl<'a, K: 'a, V: 'a> NodeRef<marker::Immut<'a>, K, V, marker::LeafOrInternal> {
    /// Asserts that the back pointer in each reachable node points to its parent.
    pub fn assert_back_pointers(self) {
        if let ForceResult::Internal(node) = self.force() {
            for idx in 0..=node.len() {
                let edge = unsafe { Handle::new_edge(node, idx) };
                let child = edge.descend();
                assert!(child.ascend().ok() == Some(edge));
                child.assert_back_pointers();
            }
        }
    }

    pub fn dump_keys(self) -> String
    where
        K: Debug,
    {
        let mut result = String::new();
        self.visit_nodes_in_order(|pos| match pos {
            navigate::Position::Leaf(leaf) => {
                let depth = self.height();
                let indent = "  ".repeat(depth);
                result += &format!("\n{}", indent);
                for idx in 0..leaf.len() {
                    if idx > 0 {
                        result += ", ";
                    }
                    result += &format!("{:?}", unsafe { leaf.key_at(idx) });
                }
            }
            navigate::Position::Internal(_) => {}
            navigate::Position::InternalKV(kv) => {
                let depth = self.height() - kv.into_node().height();
                let indent = "  ".repeat(depth);
                result += &format!("\n{}{:?}", indent, kv.into_kv().0);
            }
        });
        result
    }
}

#[test]
fn test_splitpoint() {
    for idx in 0..=CAPACITY {
        let (middle_kv_idx, insertion) = splitpoint(idx);

        // Simulate performing the split:
        let mut left_len = middle_kv_idx;
        let mut right_len = CAPACITY - middle_kv_idx - 1;
        match insertion {
            InsertionPlace::Left(edge_idx) => {
                assert!(edge_idx <= left_len);
                left_len += 1;
            }
            InsertionPlace::Right(edge_idx) => {
                assert!(edge_idx <= right_len);
                right_len += 1;
            }
        }
        assert!(left_len >= MIN_LEN_AFTER_SPLIT);
        assert!(right_len >= MIN_LEN_AFTER_SPLIT);
        assert!(left_len + right_len == CAPACITY);
    }
}

#[test]
fn test_partial_cmp_eq() {
    let mut root1: Root<i32, ()> = Root::new_leaf();
    let mut leaf1 = unsafe { root1.leaf_node_as_mut() };
    leaf1.push(1, ());
    root1.push_internal_level();
    let root2: Root<i32, ()> = Root::new_leaf();

    let leaf_edge_1a = root1.node_as_ref().first_leaf_edge().forget_node_type();
    let leaf_edge_1b = root1.node_as_ref().last_leaf_edge().forget_node_type();
    let top_edge_1 = root1.node_as_ref().first_edge();
    let top_edge_2 = root2.node_as_ref().first_edge();

    assert!(leaf_edge_1a == leaf_edge_1a);
    assert!(leaf_edge_1a != leaf_edge_1b);
    assert!(leaf_edge_1a != top_edge_1);
    assert!(leaf_edge_1a != top_edge_2);
    assert!(top_edge_1 == top_edge_1);
    assert!(top_edge_1 != top_edge_2);

    assert_eq!(leaf_edge_1a.partial_cmp(&leaf_edge_1a), Some(Equal));
    assert_eq!(leaf_edge_1a.partial_cmp(&leaf_edge_1b), Some(Less));
    assert_eq!(leaf_edge_1a.partial_cmp(&top_edge_1), None);
    assert_eq!(leaf_edge_1a.partial_cmp(&top_edge_2), None);
    assert_eq!(top_edge_1.partial_cmp(&top_edge_1), Some(Equal));
    assert_eq!(top_edge_1.partial_cmp(&top_edge_2), None);

    root1.pop_internal_level();
    unsafe { root1.into_ref().deallocate_and_ascend() };
    unsafe { root2.into_ref().deallocate_and_ascend() };
}

#[test]
#[cfg(target_arch = "x86_64")]
fn test_sizes() {
    assert_eq!(core::mem::size_of::<LeafNode<(), ()>>(), 16);
    assert_eq!(core::mem::size_of::<LeafNode<i64, i64>>(), 16 + CAPACITY * 8 * 2);
    assert_eq!(core::mem::size_of::<InternalNode<(), ()>>(), 112);
    assert_eq!(core::mem::size_of::<InternalNode<i64, i64>>(), 112 + CAPACITY * 8 * 2);
}
