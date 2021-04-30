# shannoning

A (lightning) fast permutation entropy calculator using Eigen.


## Permutation entropy
The _permutation entropy_ of order ![n \geq 2
](https://render.githubusercontent.com/render/math?math=%5Ctextstyle+n+%5Cgeq+2%0A) is defined as

![H(n) = - \sum p(\pi) \log p(\pi)
](https://render.githubusercontent.com/render/math?math=%5Cdisplaystyle+H%28n%29+%3D+-+%5Csum+p%28%5Cpi%29+%5Clog+p%28%5Cpi%29%0A)

where the sum runs over all ![n!
](https://render.githubusercontent.com/render/math?math=%5Ctextstyle+n%21%0A) permutations ![\pi
](https://render.githubusercontent.com/render/math?math=%5Ctextstyle+%5Cpi%0A) of order ![n
](https://render.githubusercontent.com/render/math?math=%5Ctextstyle+n%0A) . It is clear that ![0 \leq H(n) \leq \log n!](https://render.githubusercontent.com/render/math?math=%5Ctextstyle+0+%5Cleq+H%28n%29+%5Cleq+%5Clog+n%21) where the lower bound is attained for an increasing or decreasing sequence of (deterministic) values, and the upper bound for a completely random system (i.i.d. sequence). 



## Dependencies
 - Eigen (3.4-rc1)

---

## References

<a id="1">[1]</a>
Bandt, C., & Pompe, B. (2002). Permutation entropy: a natural complexity measure for time series. _Physical review letters_, _88_(17), 174102.
