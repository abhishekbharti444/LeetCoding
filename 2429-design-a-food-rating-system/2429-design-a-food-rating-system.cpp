class FoodRatings {
public:
    /*
        Approach : Inspired by vortubac's solution. https://leetcode.com/problems/design-a-food-rating-system/discuss/2324669/Three-Maps
            1. cuisine_ratings maps cuisine to food, ordered by rating (we use a sorted set).
            2. food_cuisine maps food to cuisine.
            3. food_ratings maps food to the current rating.
            4. For the changeRating operation, we first get the cuisine and current rating for the food.
            5. Then, we remove the old food rating from cuisine_ratings, and add the new one.

            Implementation note: since we need to return food with the highest rating, we put a negative rating into the set.
            That way, we do not have to provide a custom comparator.
    */ 
    unordered_map<string, set<pair<int, string>>> cuisine_rating;
    unordered_map<string, string> food_cuisine;
    unordered_map<string, int> food_rating;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; ++i) {
            food_rating[foods[i]] = ratings[i];
            food_cuisine[foods[i]] = cuisines[i];
            cuisine_rating[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = food_cuisine[food];
        int old_rating = food_rating[food];
        cuisine_rating[cuisine].erase({-old_rating, food});
        cuisine_rating[cuisine].insert({-newRating, food});
        food_rating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        auto [rating, food] = *cuisine_rating[cuisine].begin();
        return food;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */