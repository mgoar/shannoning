# shannoning

A (lightning) fast permutation entropy calculator using Eigen.


## Permutation entropy
The _permutation entropy_ of order $n \geq 2$ is defined as

$$
H(n) = - \sum p(\pi) \log p(\pi)
$$

where the sum runs over all $n!$ permutations $\pi$ of order $n$ . It is clear that $0 \leq H(n) \leq \log n!$ where the lower bound is attained for an increasing or decreasing sequence of (deterministic) values, and the upper bound for a completely random system (i.i.d. sequence). 



## Dependencies
 - Eigen (3.4-rc1)

---

## References

<a id="1">[1]</a>
Bandt, C., & Pompe, B. (2002). Permutation entropy: a natural complexity measure for time series. _Physical review letters_, _88_(17), 174102.
