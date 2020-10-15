data Dict k v = Dict [(k,v)]
            deriving(Show)

find :: (Eq a) => Dict a b -> a -> Maybe b
find (Dict []) _ = Nothing
find (Dict ((k,v):ps)) nk  | (k == nk) = Just v
                           | otherwise = find (Dict ps) nk

instance Functor (Dict a) where
    fmap f (Dict ps) = Dict (map (fmap f) ps)

addDic :: Dict a b -> (a,b) -> Dict a b
addDic (Dict ps) (k,v) = Dict ((k,v):ps)--Dict (ps ++[(k,v)])   

merge :: (Eq v, Eq k) => Dict k v -> Dict k v -> Dict k v
merge (Dict []) (Dict ps) = Dict ps
merge (Dict xs) (Dict []) = Dict xs
merge (Dict xs) (Dict ((k,v):ps)) |find (Dict xs) k == Nothing = (addDic (merge (Dict xs) (Dict ps)) (k,v))
                                  |otherwise = merge (Dict xs) (Dict ps)

remove :: Eq a => Dict a b -> a -> Dict a b
remove (Dict []) _ = Dict []
remove (Dict ((k,v):ps)) nk  | k == nk = Dict ps
                            | otherwise = addDic (remove (Dict ps) nk) (k,v)

update :: (Eq v, Eq k) => Dict k v -> Dict k v -> Dict k v
update (Dict []) (Dict new) = Dict new
update (Dict ori) (Dict []) = Dict ori
update (Dict ((k,v):ori)) (Dict new)|find (Dict new) k == Nothing = (addDic (update (Dict ori) (Dict new)) (k,v))
                                    |otherwise = update (Dict ori) (Dict new)