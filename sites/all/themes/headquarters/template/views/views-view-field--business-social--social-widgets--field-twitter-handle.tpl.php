<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
?>

<?php if (isset($row->field_field_twitter_handle[0]['raw']['value'])):

  $handle = $row->field_field_twitter_handle[0]['raw']['value']; ?>

  <div class="block-title padding-top-40">
    <h2><span>Twitter<br>@<?=$handle?></span></h2>
  </div>

  <?php
    $widget = module_invoke('widget', 'block_view', 'widget_twitter');
    print render($widget);
  ?>

<?php else: ?>

  <div class="block-title padding-top-40">
    <h2><span>Latest News and Posts</span></h2>
  </div>
  <?php
    $block = module_invoke('views', 'block_view', 'article-block_1');
    print render($block);
  ?>

<?php endif; ?>