# 随机变量分布

对应        映射  
基本事件 -> 样本点  -> 分布函数  

设E的样本空间为$\Omega$，对于每一个样本点  
$\omega \in \Omega$，都有唯一实数$X(\omega)$与之对应,且对于  
任意实数$x$，事件 $\{\omega \mid X(\omega) \leq x\}$ 都有确定的  
概率，则称$X(\omega)$为随机变量，简记为$X$.  

# 分布函数  

分布函数$F(x)$为随机点落在$(-\infty, x]$的概率  

$\Delta F(x) = F(x + \Delta x) - F(x)$为随机点落在某一区间$(x, x+\Delta x]$的概率  

性质:  

- 单调不降  

- $0 \leq F(x) \leq 1$  

- 右连续:  

  $F(x^+) = F(x)$  

  常用于判断是不是一个分布函数  

  或者求参数  

# 分布律  

## 离散型随机变量  
定义:  
随机变量只有有限的取值点  

$p_i = P\{X = x_i\}$，$i = 1, 2, \cdots$为$X$的分布律(某些  
教材又称之为概率质量函数).  

性质:  

- 非负性:  

  $p_i \geq 0$  

- 归一性:  

  $\sum_{i} p_i = 1$  

二项分布  

- (0/1分布)是一种特殊的二项分布$X \sim B(1, p)$  

- 只有两个基本事件:  

  $A, \neg A$  

- $n$次重复独立试验(伯努利试验)  

- 每次实验条件不变，结果互不影响  

- 研究$A$首次发生的实验次数，  

  - 几何分布  

    - 无后效性  

  - $A$第$r$次发生的试验次数  

    - 负二项分布(帕斯卡)  

    $P\{X = t\} = C\binom{t-1}{r-1} p^r q^{t-r}$  

  - $n$次试验中$A$发生的次数  

    - 是一种二项分布  

    $P\{X = k\} = C\binom{n}{k} p^k (1 - p)^{n-k}$  

泊松分布  

$p\{X = k\} = \frac{\lambda^k}{k!} * e^{-\lambda}$  

当$n$足够大,$p$足够小时  

二项分布可以近似为泊松分布  

$X \sim B(n, p) \approx X \sim Pois(\lambda)$  

$P\{X = k\} = \binom{n}{k} p^k (1 - p)^{n-k} \approx \frac{\lambda^k}{k!} *  e^{-\lambda}$  

## 连续型随机变量  

定义:  

设随机变量$X$的分布函数为$F(x)$, 若存在非负  
函数$f(x)$, 对于任意实数$x$, 均有  

$F(x) = \int_{-\infty}^{x} f(t) \, dt$  

则称随机变量$X$是连续型随机变量, 称函数  
$f(x)$为$X$的概率密度函数, 简称概率密度。  

分布函数性质:  

- $F(x)$连续  

- $P\{X = x_0\} = 0$  

- $P\{\varnothing\} = 0$, 但是其逆不真  

概率密度函数性质:  
- $f(x) \geq 0$  

- $\int_{-\infty}^{+\infty} f(x) \, dx = 1$  

- $P\{x_1 \leq X < x_2\} = P\{x_1 < X \leq x_2\} = P\{x_1 < X < x_2\} = P\{x_1 \leq X \leq x_2\} = \int_{x_1}^{x_2} f(x) \, dx$  

若$f(x)$在点$x$处连续,则有  
$F'(x) = f(x)$  

常见分布:  

- 均匀分布  

  到各个点的概率相同  

- 指数分布  

  概率密度函数  

  $f(x) = \begin{cases} \lambda e^{-\lambda x}, & \text{if } x \geq 0 \\ 0, & \text{if } x < 0 \end{cases}$  

  分布函数  
  $F(x) = \begin{cases} 1 - e^{-\lambda x}, & \text{if } x \geq 0 \\ 0, & \text{if } x < 0 \end{cases}$  

  无后效性  

  $P\{X > x + s \mid X > x\} = P\{X > s\}$  

- 正态分布  

  $F(x) = \frac{1}{\sigma \sqrt{2\pi}} \int_{-\infty}^{x} e^{-\frac{(t-\mu)^2}{2\sigma^2}} \, dt$  

  当$\mu = 0$, $\sigma = 1$时 标准正态分布  

  性质:  

  - 曲线面积为 1  

  - 沿$x = \mu$对称  

  - 3σ原理  

    - $P\{\mu - \sigma < X < \mu + \sigma\} = 0.6826$  
    - $P\{\mu - 2\sigma < X < \mu + 2\sigma\} = 0.9545$  
    - $P\{\mu - 3\sigma < X < \mu + 3\sigma\} = 0.9973$  

  曲线特征:  

  - $x = \mu$时函数取得最大值为$\frac{1}{\sigma \sqrt{2\pi}}$  

  - 一般情况分布函数为$F(x) = \frac{1}{\sigma \sqrt{2\pi}} \int_{-\infty}^{x} e^{-\frac{(t-\mu)^2}{2\sigma^2}} \, dt$  

  - $0, 1$情况  

  - 由正态分布表,求分布概率:  

    - $0, 1$情况  

      $P\{a \leq X \leq b\} = \Phi(b) - \Phi(a)$  

    - $\mu, \sigma$情况  

      $P\{a \leq X \leq b\} = \Phi\left(\frac{b - \mu}{\sigma}\right) - \Phi\left(\frac{a - \mu}{\sigma}\right)$
