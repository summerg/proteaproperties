<?php
/**
 * @file
 * gavias_mdeal_testimonial_features.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function gavias_mdeal_testimonial_features_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'testimonials';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Testimonials';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Testimonials';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_testimonial_image']['id'] = 'field_testimonial_image';
  $handler->display->display_options['fields']['field_testimonial_image']['table'] = 'field_data_field_testimonial_image';
  $handler->display->display_options['fields']['field_testimonial_image']['field'] = 'field_testimonial_image';
  $handler->display->display_options['fields']['field_testimonial_image']['label'] = '';
  $handler->display->display_options['fields']['field_testimonial_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_testimonial_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_testimonial_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Name */
  $handler->display->display_options['fields']['field_testimonial_name']['id'] = 'field_testimonial_name';
  $handler->display->display_options['fields']['field_testimonial_name']['table'] = 'field_data_field_testimonial_name';
  $handler->display->display_options['fields']['field_testimonial_name']['field'] = 'field_testimonial_name';
  $handler->display->display_options['fields']['field_testimonial_name']['label'] = '';
  $handler->display->display_options['fields']['field_testimonial_name']['element_label_colon'] = FALSE;
  /* Field: Content: Job */
  $handler->display->display_options['fields']['field_testimonial_job']['id'] = 'field_testimonial_job';
  $handler->display->display_options['fields']['field_testimonial_job']['table'] = 'field_data_field_testimonial_job';
  $handler->display->display_options['fields']['field_testimonial_job']['field'] = 'field_testimonial_job';
  $handler->display->display_options['fields']['field_testimonial_job']['label'] = '';
  $handler->display->display_options['fields']['field_testimonial_job']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'testimonial' => 'testimonial',
  );

  /* Display: Testimonials v1 */
  $handler = $view->new_display('block', 'Testimonials v1', 'testimonials_v1');

  /* Display: Testimonials v2 */
  $handler = $view->new_display('block', 'Testimonials v2', 'testimonials_v2');
  $export['testimonials'] = $view;

  return $export;
}
