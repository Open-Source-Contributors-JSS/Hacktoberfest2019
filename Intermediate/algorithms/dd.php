<?php
if (!function_exists('dd')) {
    function dd()
    {
        var_dump(func_get_args());
        die;
    }
}
