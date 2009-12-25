declare -i x
for (( x=0 ; x<31 ; x++ ))
do
echo "#version 3.5;" > anim.pov
echo "//temps entre 0 et 2*pi" >> anim.pov
echo "#declare temps=$x/5.0;" >> anim.pov
echo "#include \"scene1.pov\"" >> anim.pov
povray +Ovol$((x+100)).png anim.pov
convert -transparent "rgb(255,255,000)" -resize 25% -depth 8 vol$((x+100)).png vol$((x+100)).png
done
