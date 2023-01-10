if (isset(newRoom) || !isset(haveInput))
{  return();}if (said("examine", "area") || said("examine"))
{  print("The soft, loamy soil of the forest here gives way to the sands of the "    "great desert stretching off to the west.");}if (said("examine", "flower"))
{  print("The flowers are pretty, but otherwise uninteresting to you.");}if (said("examine", "forest"))
{  print("The trees here cast a refreshing shade.");}if ((said("examine", "flower") ||  said("smell", "flower")))
{  print("There are no flowers in this area.");}if (said("examine", "deck"))
{  print("The soft, loamy soil of the forest here gives way to the sands of the "    "great desert stretching off to the west.");}if (said("examine", "sky"))
{  print("The clear, blue sky is brilliant with an occasional white cloud.");}if (said("capture", "flower") || said("capture", "flower"))
{  print("There are no wildflowers to pick here.");}if (said("climb", "forest"))
{  print("None of these trees are suitable for climbing.");}return();[Messages#message 1 "The soft, loamy soil of the forest here gives way to the sands of the great desert stretching off to the west."#message 2 "The flowers are pretty, but otherwise uninteresting to you."#message 3 "The trees here cast a refreshing shade."#message 4 ""#message 5 "There are no flowers in this area."#message 6 ""#message 7 ""#message 8 ""#message 9 "The clear, blue sky is brilliant with an occasional white cloud."#message 10 "There are no wildflowers to pick here."#message 11 "None of these trees are suitable for climbing."


