from abc import ABC, abstractmethod

from dataclasses import dataclass
from typing import Callable, Type

import matplotlib.pyplot as plt
import networkx as nx


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

    def __init__(self, obj_type: Type['Object']) -> None:
        self._graph = nx.Graph()
        self._obj_type = obj_type

    @property
    def size(self) -> int:
        return len(self._graph.nodes())
    
    def add_node(self, obj: Object) -> None:
        pass

    @abstractmethod
    def load_nodes(self, obj_list: list[Object]) -> None:
        pass

    def get_friends(self, el: Object) -> list[Object]:  # that is not quite list
        return self._graph.neighbors(el)

    def find_local_min(self, target: Object) -> Object:  # TODO: improve
        min_ = float('inf')
        res_ = None
        for node in self._graph.nodes():
            if target.dist(node) < min_:
                min_ = target.dist(node)
                res_ = node
            
            for friend in self._graph.neighbors(node):
                if target.dist(friend) < min_:
                    min_ = target.dist(friend)
                    res_ = friend
        return res_

    def multi_search(self, target: Object) -> Object:  # TODO: improve
        mins = set()
        new_element = self.find_local_min(target)
        if new_element is not None:
            mins.add(new_element)
        return mins
    
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
    
    def show(self) -> None:
        nx.draw(self._graph, with_labels=True)
        plt.show()



