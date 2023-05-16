from abc import ABC, abstractmethod

from dataclasses import dataclass
from typing import Callable, Type

from random import randint

import matplotlib.pyplot as plt
import plotly.graph_objects as go
import networkx as nx

from sortedcontainers import SortedSet


@dataclass(frozen=True)
class Object(ABC):
    @abstractmethod
    def dist(self, other: 'Object') -> float:  # maybe improve this
        pass

    @abstractmethod
    def __eq__(self, other: 'Object') -> bool:
        pass

class NSWG(ABC):
    _graph: nx.Graph 
    _obj_type: Type['Object']
    
    _sum_degree: int

    _multi_search_queries: int

    def __init__(self, obj_type: Type['Object']) -> None:
        self._graph = nx.Graph()
        self._obj_type = obj_type
        self._sum_degree = 0

        self._multi_search_queries = 10

    @property
    def size(self) -> int:
        return len(self._graph.nodes())

    @property
    def degree(self) -> int:
        return self._sum_degree / self.size

    @property
    def cc(self):
        cc_node = 0
        for node in self._graph.nodes():
            deg = self._graph.degree(node)
            if deg < 2:
                continue
            friends = self.get_friends(node)
            cnt = 0
            for friend1 in friends:
                for friend2 in friends:
                    if self._graph.has_edge(friend1, friend2):
                        cnt += 1
            cc_node += cnt / (deg * (deg - 1))
        return cnt / self.size

    def add_node(self, obj: Object) -> None:
        pass

    @abstractmethod
    def load_nodes(self, obj_list: list[Object]) -> None:
        pass

    def get_friends(self, el: Object) -> list[Object]:  # that is not quite list
        return self._graph.neighbors(el)

    def __find_local_min(self, target_node: Object, start_node: Object) -> Object:  # TODO: improve
        min_dist = start_node.dist(target_node)
        next_node = None
        current_node = start_node
        for friend_node in self.get_friends(current_node):
            if target_node.dist(friend_node) < min_dist:
                min_dist = target_node.dist(friend_node)
                next_node = friend_node
        if next_node is None:
            return current_node
        else:
            return self.__find_local_min(target_node, next_node)

    def multi_search(self, target: Object) -> Object:
        local_mins = SortedSet(key=lambda x: x.dist(target))
        for _ in range(self._multi_search_queries):
            if self.size != 0:
                random_node_idx = randint(0, self.size - 1)
                new_element = self.__find_local_min(target, list(self._graph._node)[random_node_idx])  # TODO: make an inheritence of Graph()
                local_mins.add(new_element)
        return local_mins
    
    def get_nearest_neighbours(self, target: Object, k: int = 1):
        neighbours = self.multi_search(target)
        nsize = min(k, len(neighbours))  # TODO: fix this
        return [neighbours[i] for i in range(nsize)]

    def __str__(self) -> str:
        st = ""
        st += "graph db {\n"
        
        for el in self._graph:
            st += "    " + str(el) + " -> "
            for friend in self.get_friends(el):
                st += str(friend) + " "
            st += "\n"

        st += "} size(" + str(self.size) + ")\n"
        return st
    
    def show(self, target: Object = None, closest: list[Object] = None) -> None:
        nodes = self._graph.nodes()
        edges = self._graph.edges()

        node_x = [node.x for node in nodes]
        node_y = [node.y for node in nodes]

        edge_x = list()
        edge_y = list()
        for edge in edges:
            node1 = edge[0]
            node2 = edge[1]
            edge_x.extend([node1.x, node2.x, None])
            edge_y.extend([node1.y, node2.y, None])

        fig = go.Figure()

        fig.add_trace(go.Scatter(
            x=edge_x, 
            y=edge_y, 
            mode='lines', 
            marker=dict(size=1, color='blue')
        )) 

        if target is not None:
            print('Target', target)
            fig.add_trace(go.Scatter(
                x = [target.x],
                y = [target.y],
                mode = 'markers',
                marker=dict(size=25, color='black')
            ))

        fig.add_trace(go.Scatter(
            x=node_x, 
            y=node_y, 
            mode='markers', 
            marker=dict(size=20, color='red')
        ))

        if closest is not None:
            closest_node_x = [node.x for node in closest]
            closest_node_y = [node.y for node in closest]
            print('Target', target)
            fig.add_trace(go.Scatter(
                x = closest_node_x,
                y = closest_node_y,
                mode = 'markers',
                marker=dict(size=21, color='green')
            ))
        
        fig.show()


