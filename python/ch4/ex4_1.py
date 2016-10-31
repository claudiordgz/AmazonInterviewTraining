"""
    Route Between Nodes:
    Given a directed graph, design an algorithm to find out whether
    there is a node between two nodes
"""


def search(graph, start, end, path=[]):
    path = path + [start]
    if start == end:
        return path

    if start not in graph:
        return None

    for node in graph[start]:
        if node not in path:
            newpath = search(graph, node, end, path)
            if newpath:
                return newpath

    return None


def test_search_single_node():
    g = {
        'A': []
    }
    assert not search(g, 'A', 'G')


def test_search_cycle():
    g = {
        'A': ['B'],
        'B': ['C'],
        'C': ['A']
    }
    assert search(g, 'A', 'C') == ['A', 'B', 'C']


def test_search_one():
    g = {
        'A': ['B', 'D', 'H'],
        'B': ['C', 'G'],
        'C': ['D', 'G']
    }
    assert search(g, 'A', 'G') == ['A', 'B', 'C', 'G']


if __name__ == '__main__':
    test_search_one()
    test_search_single_node()
    test_search_cycle()



