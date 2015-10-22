#TP Limites de perception visuelle

##Application de test

```
1. Elle est capable d�afficher l�image gauche seule, l�image droite seule ou deux images en
st�r�o via le mode Quad Buffer d�OpenGL. Pour cela elle fera appel une ou deux fois �
une fonction d�affichage en fonction de param�tres dx et dy repr�sentant la parallaxe,
c�est-�-dire le d�calage entre les objets sur les deux images. Il faudra penser � ajoutet
GLUT_DOUBLE et GLUT_STEREO dans le display mode.
2. Cette fonction d�affichage devra �tre capable d�afficher plusieurs types d�objet selon le
param�trage de l�application : un point (repr�sent� sous la forme d�un disque plein),
une ligne verticale, une ligne horizontale ou une image
3. Les interactions possibles seront les suivantes :
� augmenter et diminuer la parallaxe horizontale (le pas devra �tre r�glable)
� augmenter et diminuer la parallaxe verticale (le pas devra �tre r�glable)
� changer l�objet affich�
� quitter l�application
```

##EXP�RIENCES DE PERCEPTION VISUELLE

###MESURES ET CALCULS PR�LIMINAIRES

1. La distance ds entre vos yeux et l��cran

```dyeux = 69 cm```

2. Calculer votre champ visuel horizontal FOVh par rapport � l��cran
```
�cran
|
|
|<---------------------- (yeux)
|
|
|
```

Donc l'angle est de:
```FOVh = 2*arctan(L(�cran)/(2*dyeux)) = 0.82 rad = 47 degr�s```

3. Calculer la taille s d�un pixel � l��cran en minutes d�angle
Il y a 1920 pixels sur une ligne horisontale de l'�cran. 
```s = (47/1920)*60 = 1.47 minutes d'angle.```

4.Tracez les courbes *FOVh(ds)* et *s(ds)* en faisant bien appara�tre *ds*

![](CourbeFOVh.jpg)

Ce qui m'�tonne avec cette courbe, c'est qu'elle est croissante, alors que j'aurais tendance � penser que quand la distande � l'�cran augmente, l'angle de vue diminue, non? 

###PARALLAXE

�tablissez les �quations qui relient la parallaxe � l��cran (dx et dy ) � la disparit� r�tinienne
exprim�e sous forme angulaire.



####Mesures

1. la disparit� r�tinienne maximale que vous pouvez supporter en continu, c�est-�-dire
en partant de dx = 0 et en augmentant progressivement sa valeur

2. la disparit� r�tinienne maximale que vous pouvez supporter en fermant les yeux quelques
secondes et les rouvrant sur l��cran

3. les m�mes mesures pour la parallaxe verticale

