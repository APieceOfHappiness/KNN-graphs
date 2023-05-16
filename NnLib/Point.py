from NnLib.NSWG import Object 
from dataclasses import dataclass
import numpy as np

import random

@dataclass(frozen=True)
class Point(Object):
    x: float
    y: float
    
    def dist(this, p2) -> float:
        return dist(this, p2)
    
    def __str__(this) -> str:
        return "(" + str(this.x) + ", " + str(this.y) + ")"
    
    def __eq__(self, other) -> bool:
        return self.x == other.x and self.y == other.y
    
    def random_point(begin: int = 0, end: int = 10) -> float:
        x = random.randint(begin, end)
        y = random.randint(begin, end)
        return Point(x, y)

def dist(p1: Point, p2: Point) -> float:
    return np.sqrt((p1.x - p2.x) ** 2 + (p1.y - p2.y) ** 2)