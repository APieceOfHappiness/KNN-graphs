import pandas as pd
from NSWG import NSWG, Object
from typing import Callable, Type

class GraphTester:
    __graph: NSWG
    __object_type: Object

    def __init__(self, graph: NSWG, object_type: Object):
        self.__graph = graph()
        self.__object_type = object_type

    def build_test(self, 
                   node_range_nums: range, 
                   node_val_begin: int = 1, 
                   node_val_end: int = 100, 
                   repeats: int = 1, 
                   return_info=None):
        if not (hasattr(self.__object_type, "random") and Callable(getattr(self.__object_type, "random"))):
            raise AttributeError("random has to be implemented in Object class")

        for num in node_range_nums:
            for _ in range(repeats):
                nodes = list()
                self.__graph.clean()
                for node_idx in range(num):
                    obj = self.__object_type.random(begin=node_val_begin, end=node_val_end)
                    nodes.append(obj)
                self.__graph.load_nodes(nodes)

            


        
