import java.lang.*;
import java.util.*;
import java.io.*;

public class Solution {

	static class Pair<K, V> {
		private K key;
		private V value;

		public Pair(K paramK, V paramV) {
			this.key = paramK;
			this.value = paramV;
		}

		public K getKey() {
			return this.key;
		}

		public V getValue() {
			return this.value;
		}

		public int hashCode() {
			return this.key.hashCode() * 13 + (this.value == null ? 0 : this.value.hashCode());
		}
		public boolean equals(Object paramObject) {
			if (this == paramObject) { return true; }
			if ((paramObject instanceof Pair)) {
				Pair localPair = (Pair)paramObject;
				if (this.key != null ? !this.key.equals(localPair.key) : localPair.key != null) { return false; }
				if (this.value != null ? !this.value.equals(localPair.value) : localPair.value != null) { return false; }
				return true;
			}
			return false;
		}
	}

	private int L;
	private Map<String, List<String>> allComboDict;

	Solution() {
		this.L = 0;
		// Dictionary to hold combination of words that can be formed,
		// from any given word. By changing one letter at a time.
		this.allComboDict = new HashMap<>();
	}

	private int visitWordNode(
	    Queue<Pair<String, Integer>> Q,
	    Map<String, Integer> visited,
	    Map<String, Integer> othersVisited) {
		Pair<String, Integer> node = Q.remove();
		String word = node.getKey();
		int level = node.getValue();
		for (int i = 0; i < this.L; i++) {
			// Intermediate words for current word
			String newWord = word.substring(0, i) + '*' + word.substring(i + 1, L);
			// Next states are all the words which share the same intermediate state.
			for (String adjacentWord : this.allComboDict.getOrDefault(newWord, new ArrayList<>())) {
				// If at any point if we find what we are looking for
				// i.e. the end word - we can return with the answer.
				if (othersVisited.containsKey(adjacentWord)) {
					return level + othersVisited.get(adjacentWord);
				}
				if (!visited.containsKey(adjacentWord)) {
					// Save the level as the value of the dictionary, to save number of hops.
					visited.put(adjacentWord, level + 1);
					Q.add(new Pair(adjacentWord, level + 1));
				}
			}
		}
		return -1;
	}

	public int solve(String beginWord, String endWord, ArrayList<String> wordList) {
		if (!wordList.contains(endWord)) {
			return 0;
		}
		// Since all words are of same length.
		this.L = beginWord.length();
		wordList.forEach(
		word -> {
			for (int i = 0; i < L; i++) {
				// Key is the generic word
				// Value is a list of words which have the same intermediate generic word.
				String newWord = word.substring(0, i) + '*' + word.substring(i + 1, L);
				List<String> transformations =
				this.allComboDict.getOrDefault(newWord, new ArrayList<>());
				transformations.add(word);
				this.allComboDict.put(newWord, transformations);
			}
		});
		// Queues for birdirectional BFS
		// BFS starting from beginWord
		Queue<Pair<String, Integer>> Q_begin = new LinkedList<>();
		// BFS starting from endWord
		Queue<Pair<String, Integer>> Q_end = new LinkedList<>();
		Q_begin.add(new Pair(beginWord, 1));
		Q_end.add(new Pair(endWord, 1));
		// Visited to make sure we don't repeat processing same word.
		Map<String, Integer> visitedBegin = new HashMap<>();
		Map<String, Integer> visitedEnd = new HashMap<>();
		visitedBegin.put(beginWord, 1);
		visitedEnd.put(endWord, 1);
		while (!Q_begin.isEmpty() && !Q_end.isEmpty()) {
			// One hop from begin word
			int ans = visitWordNode(Q_begin, visitedBegin, visitedEnd);
			if (ans > -1) {
				return ans;
			}
			// One hop from end word
			ans = visitWordNode(Q_end, visitedEnd, visitedBegin);
			if (ans > -1) {
				return ans;
			}
		}
		return 0;
	}
}
