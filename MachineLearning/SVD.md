---
title: SVD
date: 2018-11-26 14:42:15
tags:
  - 神经网络

categories: 机器学习
---
PCA的实现一般有两种，一种是用特征值分解去实现的，一种是用奇异值分解去实现的。
PCA确定主方向步骤：
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1)建立协方差矩阵
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2)矩阵最大特征值对应的特征向量为主方向。<!--more-->
## 特征值
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;如果说一个向量v是方阵A的特征向量，将一定可以表示成下面的形式：<a href="https://www.codecogs.com/eqnedit.php?latex=Av=\lambda&space;v" target="_blank"><img src="https://latex.codecogs.com/gif.latex?Av=\lambda&space;v"/></a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;这时候λ就被称为特征向量v对应的特征值，一个矩阵的一组特征向量是一组正交向量。特征值分解是将一个矩阵分解成下面的形式：
<a href="https://www.codecogs.com/eqnedit.php?latex=A=Q\Sigma&space;Q^{-1}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?A=Q\Sigma&space;Q^{-1}"/></a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;其中Q是这个矩阵A的特征向量组成的矩阵，Σ是一个对角阵，每一个对角线上的元素就是一个特征值。
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;注：一个矩阵乘以一个向量后得到的向量，其实就相当于将这个向量进行了线性变换。分解得到的Σ矩阵是一个对角阵，里面的特征值是由大到小排列的，这些特征值所对应的特征向量就是描述这个矩阵变化方向（从主要的变化到次要的变化排列）
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;我们通过特征值分解得到的前N个特征向量，那么就对应了这个矩阵最主要的N个变化方向。我们利用这前N个变化方向，就可以近似这个矩阵（变换）。也就是之前说的：提取这个矩阵最重要的特征。
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;总结一下，特征值分解可以得到特征值与特征向量，特征值表示的是这个特征到底有多重要，而特征向量表示这个特征是什么，可以将每一个特征向量理解为一个线性的子空间，我们可以利用这些线性的子空间干很多的事情。不过，特征值分解也有很多的局限，比如说变换的矩阵必须是方阵。

## 奇异值
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;特征值分解是一个提取矩阵特征很不错的方法，但是它只是对方阵而言的，在现实的世界中，我们看到的大部分矩阵都不是方阵，奇异值分解是一个能适用于任意的矩阵的一种分解的方法(奇异值分解（Singular Value Decomposition，SVD），是一种提取信息的方法。)：
<a href="https://www.codecogs.com/eqnedit.php?latex=A=U\Sigma&space;V^{\top}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?A=U\Sigma&space;V^{\top}"/></a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;假设A是一个N \* M的矩阵，那么得到的U是一个N \* N的方阵（里面的向量是正交的，U里面的向量称为左奇异向量），Σ是一个N \* M的矩阵（除了对角线的元素都是0，对角线上的元素称为奇异值），V的转置是一个N \* N的矩阵（里面的向量也是正交的，V里面的向量称为右奇异向量）。即满足
<a href="https://www.codecogs.com/eqnedit.php?latex=U^{\top}U=I" target="_blank"><img src="https://latex.codecogs.com/gif.latex?U^{\top}U=I"/></a><a href="https://www.codecogs.com/eqnedit.php?latex=V^{\top}V=I" target="_blank"><img src="https://latex.codecogs.com/gif.latex?V^{\top}V=I"/></a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;那么我们如何求出SVD分解后的U,Σ,V这三个矩阵呢？
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;A 的 左奇异向量是 AA⊤ 的特征向量。 A 的 右奇异向量是 A⊤A 的特征向量。 A 的非零奇异值是 A⊤A 特征值的平方根，同时也是AA⊤ 特征值的平方根。
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;如果我们将A的转置和A做矩阵乘法，那么会得到n×n的一个方阵 A⊤A  。既然 A⊤A 是方阵，那么我们就可以进行特征分解，得到的特征值和特征向量满足下式：
<a href="https://www.codecogs.com/eqnedit.php?latex=(A^{\top}A)v_{i}=\lambda&space;_{i}v_{i}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?(A^{\top}A)v_{i}=\lambda&space;_{i}v_{i}"/></a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;这样我们就可以得到矩阵 A⊤A 的n个特征值和对应的n个特征向量v了。将 A⊤A  的所有特征向量张成一个n×n的矩阵V，就是我们SVD公式里面的V矩阵了。一般我们将V中的每个特征向量叫做A的右奇异向量。
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;如果我们将A和A的转置做矩阵乘法，那么会得到m×m的一个方阵 AA⊤ 。既然 AA⊤ 是方阵，那么我们就可以进行特征分解，得到的特征值和特征向量满足下式：
<a href="https://www.codecogs.com/eqnedit.php?latex=(AA^{\top})v_{i}=\lambda&space;_{i}v_{i}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?(AA^{\top})v_{i}=\lambda&space;_{i}v_{i}"/></a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;这样我们就可以得到矩阵 AA⊤ 的m个特征值和对应的m个特征向量u了。将 AA⊤ 的所有特征向量张成一个m×m的矩阵U，就是我们SVD公式里面的U矩阵了。一般我们将U中的每个特征向量叫做A的左奇异向量。
求Σ，我们注意到：
<a href="https://www.codecogs.com/eqnedit.php?latex=A=U\Sigma&space;V^{\top&space;}\Rightarrow&space;AV=U\Sigma&space;V^{\top&space;}V\Rightarrow&space;AV=U\Sigma&space;\Rightarrow&space;Av_{i}=\sigma&space;_{i}u_{i}\Rightarrow&space;\sigma&space;_{i}=Av_{i}/u_{i}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?A=U\Sigma&space;V^{\top&space;}\Rightarrow&space;AV=U\Sigma&space;V^{\top&space;}V\Rightarrow&space;AV=U\Sigma&space;\Rightarrow&space;Av_{i}=\sigma&space;_{i}u_{i}\Rightarrow&space;\sigma&space;_{i}=Av_{i}/u_{i}" /></a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;还可以看出我们的特征值矩阵等于奇异值矩阵的平方，也就是说特征值和奇异值满足如下关系：<a href="https://www.codecogs.com/eqnedit.php?latex=\sigma&space;_{i}=\sqrt{\lambda&space;_{i}}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\sigma&space;_{i}=\sqrt{\lambda&space;_{i}}"/></a>

## SVD用于降维
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;PCA降维，需要找到样本协方差矩阵 X⊤X 的最大的d个特征向量，然后用这最大的d个特征向量张成的矩阵来做低维投影降维。可以看出，在这个过程中需要先求出协方差矩阵 A⊤A ，当样本数多样本特征数也多的时候，这个计算量是很大的。
注意到PCA仅仅使用了SVD的右奇异矩阵，没有使用左奇异矩阵：
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;左奇异矩阵可以用于行数的压缩。
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;右奇异矩阵可用于列数即特征维度的压缩，也就是PCA降维。