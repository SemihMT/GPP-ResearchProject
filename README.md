# GPP-ResearchProject - Rockets using the Genetic Algorithm

This project breeds "smart" rockets to fly towards a target using an implementation of a genetic algorithm.

![](https://github.com/SemihMT/GPP-ResearchProject/blob/Final/WindowsTerminal_u76k7z5BVs.gif)

The implementation is based on The Coding Train's [p5js version](https://editor.p5js.org/codingtrain/sketches/o5PwECj42)

## How it works

The logic behind the whole algorithm is derived from Darwin's theory of evolution.
The key belief behind that theory is that nature is shaped by one general rule: **Survival of the Fittest**
Thus, the algorithm does the same. 

Simply put, the algorithm works in 5 steps:

1. Create a population (of rockets in this case)
2. Update the simulation for a pre defined amount of steps, the lifespan of each "organism", if you will.
3. When the simulation ends, calculate the fitness of each organism.
4. Create a matingpool based on the fitness.
5. Create a new population by choosing two parents randomly from the matingpool, breeding them, and including mutations in the resulting child.

Repeating these steps will result in the population slowly but surely adaping in order to reach a higher fitness score.

### Creating a population

A population in the Genetic Algorithm refers to a container object that stores all the "organisms". It is responsible for creating, updating and drawing each of the contained "organisms".

### The lifetime of an organism

Defining what the lifetime is for an object is arguably one of the most important parts of the algorithm. Without it no organism would be created, and none would be killed off. Totally unnatural.

My project defines a maximum number of frames for each generation's lifetime. After the amount of frames get reached by the simulation, the current generation of organisms get killed off and a newly generated one takes its place.

### The matingpool

A solid understanding of the matingpool is very handy before going in depth about the fitness function.
The mating pool is simply a (large) container of "organisms" copied over from the population.
This mating pool gets filled according to the fitness of each "organism" in the population, making sure that when we randomly pick an element from the mating pool, the chances of us picking any one of them directly correspond to their fitness.

> An example to make things clear: 
> Let's say we have 10 organisms, all with a fitness score ranging from 1 to 10.
> The first organism has a fitness of 1 --...--> the 10th organism has a fitness of 10.

> To fill the matingpool correctly you'd make sure that there is only one copy of the organism with fitness 1, while there are 10 copies of the organism with fitness 10.
> This ensures that the organism with fitness 10 is 10 times more likely to be picked than the organism with fitness 1.

### The fitness function

Calculating the fitness happens differently depending on the type of problem you're trying to solve with the Genetic Algorithm. 
In my case the fitness is defined by how near the rocket got to the target point.
In other cases, like solving for a predefined string, the fitness function takes other forms. Choosing a good function is of utmost importance, as it is the sole thing that determines the well adapted organisms from the poorly adapted ones.

Now, depending only on the distance between the rocket and the target would mean that there would be little difference between a rocket that grazed the target and one that reached its life's end 5 units away from the target. And in nature, that difference is slim to none. But our goal is to obtain a solution to a problem as fast as possible, so there still are ways to optimize the fitness function.

One of the easiest yet most rewarding ways to optimize our fitness function is to change the shape of the function. We can make the fitness function grow exponentially. This means that small differences in distance can still result in big differences in fitness which rewards any "organism" making progress by adding more copies of the "organism" to the mating pool.

### Representing Genotypes & Phenotypes

In biology the terms Genotype and Phenotype of an organism refer to the DNA gene representation and the physical, observable characteristics of the organism.
Both of these aspects of biology must be represented in the Genetic Algorithm as well.

Again, as with the fitness function. This representation will differ from problem to problem.
I represented the **Genotype** of my rockets as a container of 2D vectors, with the container being as big as the lifespan of the organism.
The 2D vectors are impulses added to the velocity of the rocket, guiding it towards the target (hopefully).

The **Phenotype** is arguably less important in the eyes of the algorithm, only acting as feedback for the user. In my case the fenotype of the rockets are rectangles, rotating in the direction their **Genotype** guides them.
